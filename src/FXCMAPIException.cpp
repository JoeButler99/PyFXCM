/*
 * FXCMAPIException.cpp
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#include "FXCMAPIException.h"

FXCMAPIException::FXCMAPIException(const char *pMsg,
		 int ec,
		 const char *pFunc,
		 const char *pFile,
		 int line)
: mMsg(pMsg), mErrorCode(ec), mFuncName(pFunc), mFile(pFile), mLineNum(line) {}

FXCMAPIException::~FXCMAPIException() {}

std::string FXCMAPIException::display() {
	std::ostringstream out;
	out << "Error <" << mMsg << ">"
		<< " - value is " << mErrorCode << "\n"
		<< "in function " << mFuncName << "()\n"
		<< "in file " << mFile << " line#" << mLineNum << std::ends;
	return out.str();
}
