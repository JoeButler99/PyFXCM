/*
 * PyFXCM.cpp
 *
 *  Created on: 9 Dec 2014
 *      Author: joe
 */
#include <boost/python.hpp>
#include "stdafx.h"
#include "LoginParams.h"
#include "SessionHandler.h"

// Global objects
SessionHandler * sessionHandler = 0;



// Top level functions
std::string version() {
	return sem_ver_string;
}


bool is_connected() {
	if (sessionHandler == 0) {  return false; }
	else { return sessionHandler->isConnected(); }
}


void connect_with_params(LoginParams lp) {
	if (sessionHandler == 0) {
		sessionHandler = new SessionHandler(lp);
		sessionHandler->login();
	} else {

	}
}



using namespace boost::python;
BOOST_PYTHON_MODULE(PyFXCM) {
	class_<LoginParams>("LoginParams", init<std::string, std::string, optional<std::string, std::string> >())
		.def("get_login",&LoginParams::getLogin)
		.def("get_password",&LoginParams::getPassword)
		.def("get_url",&LoginParams::getURL)
		.def("get_connection_type",&LoginParams::getConnection)
	;

	boost::python::def("version", version);
	boost::python::def("is_connected", is_connected);
	boost::python::def("connect_with_params", connect_with_params);
}
