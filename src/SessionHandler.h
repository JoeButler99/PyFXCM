#pragma once
#include "stdafx.h"
#include "LoginParams.h"
#include "SessionStatusListener.h"
/*
 * SessionHandler.h
 *
 *  Created on: 28 Oct 2014
 *      Author: joe
 */



class SessionHandler {
public:
	SessionHandler(LoginParams lp);
	virtual ~SessionHandler();
	bool login();
	void logout();
	bool isConnected();
private:
	LoginParams & loginParams;
	IO2GSession * session;
	SessionStatusListener * statusListener;

};

