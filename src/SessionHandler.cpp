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
	statusListener->reset();
	session->login(loginParams.getLogin(),loginParams.getPassword(),loginParams.getURL(),loginParams.getConnection());
	return statusListener->waitEvents() && statusListener->isConnected();
}

void SessionHandler::logout() {
	statusListener->reset();
	session->logout();
	statusListener->waitEvents();
}

bool SessionHandler::isConnected() {
	return statusListener->isConnected();
}
