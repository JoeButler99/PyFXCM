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

	const IO2GSession * getSession() const {
		return session;
	}

	const SessionStatusListener * getStatusListener() const {
		return statusListener;
	}

	void attachResponseListener();

	void releaseResponseListener();

private:
	LoginParams & loginParams;
	IO2GSession * session;
	SessionStatusListener * statusListener;
	ResponseListener * responseListener = 0;

};

