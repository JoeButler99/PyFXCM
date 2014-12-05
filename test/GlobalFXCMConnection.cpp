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
		YamlConfigLoader mYamlConfigLoader("config/config.yaml");
		LoginParams mLoginParams(mYamlConfigLoader.getKey("demo_account_username"),
								 mYamlConfigLoader.getKey("demo_account_password"),
								 mYamlConfigLoader.getKey("demo_account_connectiontype"));
		mSessionHandler = new SessionHandler(mLoginParams);
	}
	return mSessionHandler;
}
