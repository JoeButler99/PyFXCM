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

class Helpers {
public:
	static void debugText(std::string msg) {
		if(debugMode) {
			std::cerr<< "DEBUG:\t" << msg << std::endl;
		}
	}

};


#endif /* HELPERS_H_ */
