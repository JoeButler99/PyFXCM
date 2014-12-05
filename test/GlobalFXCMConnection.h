/*
 * GlobalFXCMConnection.h
 *
 *  Created on: 5 Dec 2014
 *      Author: joe
 */

#ifndef GLOBALFXCMCONNECTION_H_
#define GLOBALFXCMCONNECTION_H_
#include <stddef.h>  // defines NULL
#include "../src/YamlConfigLoader.h"
#include "../src/SessionHandler.h"

class GlobalFXCMConnection {
public:
	static GlobalFXCMConnection* Instance();
	SessionHandler* getSessionHandler();

private:
	GlobalFXCMConnection() : mSessionHandler(0) {};
	GlobalFXCMConnection(GlobalFXCMConnection const&) : mSessionHandler(0) {};
	GlobalFXCMConnection& operator=(GlobalFXCMConnection const&);
	static GlobalFXCMConnection* instance;
	SessionHandler* mSessionHandler;

};

#endif /* GLOBALFXCMCONNECTION_H_ */
