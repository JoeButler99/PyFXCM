/*
 * PyFXCM.cpp
 *
 *  Created on: 9 Dec 2014
 *      Author: joe
 */

#include <boost/python.hpp>



double version() {
	return 1.0;
}



using namespace boost::python;
BOOST_PYTHON_MODULE(PyFXCM) {
	boost::python::def("version", version);
}
