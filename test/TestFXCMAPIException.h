/*
 * TestFXCMAPIException.h
 *
 *  Created on: 29 Sep 2014
 *      Author: joe
 */

#ifndef TESTFXCMAPIEXCEPTION_H_
#define TESTFXCMAPIEXCEPTION_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include <boost/regex.hpp>
#include "../src/stdafx.h"
#include "../src/FXCMAPIException.h"

class TestFXCMAPIException : public CppUnit::TestFixture {
public:
	TestFXCMAPIException(){}
	virtual ~TestFXCMAPIException(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestFXCMAPIException");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestFXCMAPIException>("Test constructor",&TestFXCMAPIException::testConstructor));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestFXCMAPIException>("Test Display",&TestFXCMAPIException::testDisplay));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "FXCMAPIException:\t" <<  __func__ << std::endl;
		FXCMAPIException fe("TestCase",5,__func__,__FILE__,__LINE__);
		CPPUNIT_ASSERT(strcmp(fe.getMsg().c_str(),"TestCase") == 0 );
		CPPUNIT_ASSERT(fe.getErrorCode() == 5);
		CPPUNIT_ASSERT(strcmp(fe.getFuncName().c_str(),"testConstructor") == 0);
		CPPUNIT_ASSERT(strcmp(fe.getFile().c_str(),"test/TestFXCMAPIException.h") == 0);
		CPPUNIT_ASSERT(fe.getLineNum() == __LINE__ - 5); // Three lines ago

	}

	void testDisplay() {
		std::cerr << "FXCMAPIException:\t" <<  __func__ << std::endl;
		FXCMAPIException fe("TestCase",7,"testFunc","testFile",20);
		std::string testDisplayExample = "Error <TestCase> - value is 7\nin function testFunc()\nin file testFile line#20";
		CPPUNIT_ASSERT(strcmp(fe.display().c_str(),testDisplayExample.c_str()) == 0);
	}
};

#endif /* TESTFXCMAPIEXCEPTION_H_ */
