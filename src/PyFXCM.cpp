/*
 * PyFXCM.cpp
 *
 *  Created on: 9 Dec 2014
 *      Author: joe
 */
#include <boost/python.hpp>
#include "stdafx.h"
#include "LoginParams.h"


std::string version() {
	return sem_ver_string;
}



using namespace boost::python;
BOOST_PYTHON_MODULE(PyFXCM) {
	boost::python::def("version", version);
}
