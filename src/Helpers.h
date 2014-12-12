/*
 * Helpers.h
 *
 *  Created on: 4 Dec 2014
 *      Author: joe
 */

#ifndef HELPERS_H_
#define HELPERS_H_
#include "stdafx.h"
#include "FXCMAPIException.h"
#include <sstream>
#include <iomanip>

class Helpers {
public:
	static void debugText(std::string msg, bool throwMsg = false) {
		if(debugMode) {
			std::cerr<< "DEBUG:\t" << msg << std::endl;
		}
		if(throwMsg) {
			throw FXCMAPIException(msg.c_str(),1,__func__,__FILE__,__LINE__);
		}
	}


	static void formatDate(DATE date, char *buf)
	{
	    struct tm tmBuf = {0};
	    CO2GDateUtils::OleTimeToCTime(date, &tmBuf);

	    using namespace std;
	    stringstream sstream;
	    sstream << setw(2) << setfill('0') << tmBuf.tm_mon + 1 << "." \
	            << setw(2) << setfill('0') << tmBuf.tm_mday << "." \
	            << setw(4) << tmBuf.tm_year + 1900 << " " \
	            << setw(2) << setfill('0') << tmBuf.tm_hour << ":" \
	            << setw(2) << setfill('0') << tmBuf.tm_min << ":" \
	            << setw(2) << setfill('0') << tmBuf.tm_sec;
	    strcpy(buf, sstream.str().c_str());
	}

};


#endif /* HELPERS_H_ */
