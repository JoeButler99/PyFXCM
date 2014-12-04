#pragma once
/*
 * SessionHandler.h
 *
 *  Created on: 28 Oct 2014
 *      Author: joe
 */

#include "stdafx.h"
#include "LoginParams.h"
#include "SessionStatusListener.h"
#include "ResponseListener.h"
#include "Helpers.h"


class SessionHandler {
public:
	SessionHandler(LoginParams lp);
	virtual ~SessionHandler();
	bool login();
	void logout();
	bool isConnected();

	IO2GSession * getSession() {
		return session;
	}

	SessionStatusListener * getStatusListener() {
		return statusListener;
	}

	ResponseListener * getResponseListener() {
		return responseListener;
	}

	void attachResponseListener();

	void releaseResponseListener();

private:
	LoginParams & loginParams;
	IO2GSession * session;
	SessionStatusListener * statusListener;
	ResponseListener * responseListener = 0;

};

