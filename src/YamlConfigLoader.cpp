/*
 * YamlConfigLoader.cpp
 *
 *  Created on: 2 Dec 2014
 *      Author: joe
 */

#include "YamlConfigLoader.h"

YamlConfigLoader::YamlConfigLoader(std::string fileName) : fileName(fileName) {}

YamlConfigLoader::~YamlConfigLoader() {}


std::string YamlConfigLoader::getKey(std::string keyName) {
	// TODO - This whole method is pretty sloppy, we should probably load the lot into a map
	// and search from there.
	if(!yaml_parser_initialize(&parser)){
		throw FXCMAPIException("Unable to initialise YAML Parser.",1,__func__,__FILE__,__LINE__);
	}
	yaml_token_t  token;
	FILE *fh = fopen(fileName.c_str(),"r");
	if (fh == NULL) {
		char msg[200];
		sprintf(msg,"Could not open file: %s",fileName.c_str());
		throw FXCMAPIException(msg,1,__func__,__FILE__,__LINE__);
	}
	yaml_parser_set_input_file(&parser,fh);

	bool getKey = false;
	bool foundKey = false;
	bool gotValue = false;
	std::string currentKey = "";
	std::string currentValue = "";
	// Start the search
	do {
		yaml_parser_scan(&parser,&token);
		switch(token.type) {
		case YAML_STREAM_START_EVENT: break;
		case YAML_STREAM_END_TOKEN: break;
		case YAML_KEY_TOKEN:
			getKey = true; // The next value is a key
			break;
		case YAML_VALUE_TOKEN:
			getKey = false; // The next value is a value
			break;
		case YAML_SCALAR_TOKEN:
			if (getKey) {
				currentKey = reinterpret_cast<char*>(token.data.scalar.value);
				if (currentKey == keyName) { foundKey = true; }
			} else {
				currentValue = reinterpret_cast<char*>(token.data.scalar.value);
				if (foundKey) { gotValue = true; }
			}
			break;
	    default:
	      break;
		}
	} while(token.type != YAML_STREAM_END_TOKEN && !gotValue);
	yaml_parser_delete(&parser);
	fclose(fh);

	if (gotValue) {
		return currentValue;
	} else {
		return "";
	}
}

