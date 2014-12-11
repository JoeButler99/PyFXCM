/*
 * GlobalFXCMConnection.cpp
 *
 *  Created on: 5 Dec 2014
 *      Author: joe
 */
#include "GlobalFXCMConnection.h"

GlobalFXCMConnection* GlobalFXCMConnection::instance = NULL;

GlobalFXCMConnection* GlobalFXCMConnection::Instance() {
	if (!instance) {
		instance = new GlobalFXCMConnection;
	}
	return instance;
}


SessionHandler* GlobalFXCMConnection::getSessionHandler() {
	if (mSessionHandler == 0) {
		Helpers::debugText("CREATE NEW SESSION");
		YamlConfigLoader mYamlConfigLoader("config/config.yaml");
		LoginParams mLoginParams = LoginParams(mYamlConfigLoader.getKey("demo_account_username"),
											   mYamlConfigLoader.getKey("demo_account_password"),
											   mYamlConfigLoader.getKey("demo_account_connectiontype"),
											   mYamlConfigLoader.getKey("demo_account_url"));
		mSessionHandler = new SessionHandler(mLoginParams);
	} else {
		Helpers::debugText("REUSE SESSION");
	}
	return mSessionHandler;
}
