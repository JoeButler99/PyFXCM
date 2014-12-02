/*
 * FXCMAPIException.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef FXCMAPIEXCEPTION_H_
#define FXCMAPIEXCEPTION_H_
#include "stdafx.h"

class FXCMAPIException {
public:
	FXCMAPIException(const char *pMsg,
					 int ec,
					 const char *pFunc,
					 const char *pFile,
					 int line);
	virtual ~FXCMAPIException();
	virtual std::string display();

	int getErrorCode() const {
		return mErrorCode;
	}

	const std::string& getFile() const {
		return mFile;
	}

	const std::string& getFuncName() const {
		return mFuncName;
	}

	int getLineNum() const {
		return mLineNum;
	}

	const std::string& getMsg() const {
		return mMsg;
	}

private:
	std::string mMsg;
	int mErrorCode;
	std::string mFuncName;
	std::string mFile;
	int mLineNum;


};

#endif /* FXCMAPIEXCEPTION_H_ */
