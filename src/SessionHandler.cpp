/*
 * SessionHandler.cpp
 *
 *  Created on: 28 Oct 2014
 *      Author: joe
 */

#include "SessionHandler.h"

SessionHandler::SessionHandler(LoginParams lp) : loginParams(lp) {}

SessionHandler::~SessionHandler() {}

bool SessionHandler::login() {
	// TODO - Memory management here
	if (session == 0) {
		Helpers::debugText(loginParams.getURL());
		Helpers::debugText(loginParams.getConnection());
		Helpers::debugText(loginParams.getPassword());
		Helpers::debugText(loginParams.getLogin());

		session = CO2GTransport::createSession();
		statusListener = new SessionStatusListener(session,false,"","");
		session->subscribeSessionStatus(statusListener);
		statusListener->reset();
	    session->login(loginParams.getLogin(), loginParams.getPassword(),
	    			   loginParams.getURL(), loginParams.getConnection());
	    return statusListener->waitEvents() && statusListener->isConnected();
	} else {
		if(isConnected()) {
			return true;
		} else {
			if (session != 0 ) {
				delete session;
				session = 0;
			}
			if (statusListener != 0) {
				statusListener->release();
				statusListener = 0;
			}
			if (responseListener != 0) {
				responseListener->release();
				responseListener = 0;
			}
			login();
			return false; // This should not be reached
		}
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
	// TODO - We might need to check the status of the session more carefully if things
	// are seen to 'go stale'
	if (statusListener == 0) {
		Helpers::debugText("REQUESTED SESSION STATUS ON AN EMPTY STATUS LISTENER");
		return false;
	} else {
		return statusListener->isConnected();
	}
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
        responseListener = 0;
	} else {
		throw FXCMAPIException("Cannot release NULL Response Listener.",1,__func__,__FILE__,__LINE__);
	}
}
