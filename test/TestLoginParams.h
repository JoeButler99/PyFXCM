/*
 * TestLoginParams.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTLOGINPARAMS_H_
#define TESTLOGINPARAMS_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/LoginParams.h"


class TestLoginParams : public CppUnit::TestFixture {
public:
	TestLoginParams(){}
	virtual ~TestLoginParams(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestLoginParams");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestLoginParams>("Test constructor",&TestLoginParams::testConstructor));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "LoginParams:\t\t" <<  __func__ << std::endl;
		LoginParams lp("TestLogin","TestPassword");
		CPPUNIT_ASSERT(strcmp(lp.getURL(),"http://www.fxcorporate.com/Hosts.jsp") == 0 );
		CPPUNIT_ASSERT(strcmp(lp.getLogin(),"TestLogin") == 0 );
		CPPUNIT_ASSERT(strcmp(lp.getPassword(),"TestPassword") == 0 );
		CPPUNIT_ASSERT(strcmp(lp.getConnection(),"Real") == 0 );


		LoginParams lp2("TestLogin2","TestPassword2","Real");
		CPPUNIT_ASSERT(strcmp(lp2.getURL(),"http://www.fxcorporate.com/Hosts.jsp") == 0 );
		CPPUNIT_ASSERT(strcmp(lp2.getLogin(),"TestLogin2") == 0 );
		CPPUNIT_ASSERT(strcmp(lp2.getPassword(),"TestPassword2") == 0 );
		CPPUNIT_ASSERT(strcmp(lp2.getConnection(),"Real") == 0 );


		CPPUNIT_ASSERT_THROW(LoginParams lp3("TestLogin3","TestPassword3","Wrong"),FXCMAPIException);

		LoginParams lp4("TestLogin4","TestPassword4","Real","http://example.com");
		CPPUNIT_ASSERT(strcmp(lp4.getURL(),"http://example.com") == 0 );
		CPPUNIT_ASSERT(strcmp(lp4.getLogin(),"TestLogin4") == 0 );
		CPPUNIT_ASSERT(strcmp(lp4.getPassword(),"TestPassword4") == 0 );
		CPPUNIT_ASSERT(strcmp(lp4.getConnection(),"Real") == 0 );

	}
};



#endif /* TESTLOGINPARAMS_H_ */
