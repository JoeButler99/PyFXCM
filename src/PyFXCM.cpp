/*
 * PyFXCM.cpp
 *
 *  Created on: 9 Dec 2014
 *      Author: joe
 */
#include <boost/python.hpp>
#include "stdafx.h"
#include "LoginParams.h"




void set_login_params(std::string login, std::string password, std::string connection , std::string url) {

}


std::string version() {
	return sem_ver_string;
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
}
