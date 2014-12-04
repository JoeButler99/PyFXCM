/*
 * SessionHandler.cpp
 *
 *  Created on: 28 Oct 2014
 *      Author: joe
 */

#include "SessionHandler.h"

SessionHandler::SessionHandler(LoginParams lp) : loginParams(lp),
								   session(CO2GTransport::createSession()),
								   statusListener(new SessionStatusListener(session,true,0,0))
{
	session->subscribeSessionStatus(statusListener);
}

SessionHandler::~SessionHandler() {}

bool SessionHandler::login() {
	if (!isConnected()) {
		Helpers::debugText(loginParams.getURL());
		Helpers::debugText(loginParams.getConnection());

		statusListener->reset();
		session->login(loginParams.getLogin(),loginParams.getPassword(),loginParams.getURL(),loginParams.getConnection());
		statusListener->waitEvents();
		return statusListener->isConnected();
	} else {
		return true;
	}

}

void SessionHandler::logout() {
	if (isConnected()) {
		statusListener->reset();
		session->logout();
		statusListener->waitEvents();
	}
}

bool SessionHandler::isConnected() {
	return statusListener->isConnected();
}

void SessionHandler::attachResponseListener() {
	if(responseListener == 0) {
		responseListener = new ResponseListener(session);
		session->subscribeResponse(responseListener);
	} else {
		throw FXCMAPIException("Cannot reassign Response Listener.",1,__func__,__FILE__,__LINE__);
	}
}

void SessionHandler::releaseResponseListener() {
	if(responseListener != 0) {
        session->unsubscribeResponse(responseListener);
        responseListener->release();
	} else {
		throw FXCMAPIException("Cannot release NULL Response Listener.",1,__func__,__FILE__,__LINE__);
	}
}
