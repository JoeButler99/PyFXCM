/*
 * YamlConfigLoader.h
 *
 *  Created on: 2 Dec 2014
 *      Author: joe
 */

#ifndef YAMLCONFIGLOADER_H_
#define YAMLCONFIGLOADER_H_
// TODO - Pick pragma once vs ifndef and fix in all headers

#include "stdafx.h"
#include "FXCMAPIException.h"
#include <yaml.h>


class YamlConfigLoader {
	//
	// This class is very closely based on: https://www.wpsoftware.net/andrew/pages/libyaml.html
	//
private:
	std::string fileName;
	yaml_parser_t parser;
public:
	YamlConfigLoader(std::string fileName);
	virtual ~YamlConfigLoader();
	std::string getKey(std::string keyName);
};

#endif /* YAMLCONFIGLOADER_H_ */
