/*
 * TestSessionHandler.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTSESSIONHANDLER_H_
#define TESTSESSIONHANDLER_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/SessionHandler.h"
#include "GlobalFXCMConnection.h"

class TestSessionHandler : public CppUnit::TestFixture {
private:
	YamlConfigLoader configLoader = YamlConfigLoader("config/config.yaml");
	LoginParams demoLoginParams = LoginParams(configLoader.getKey("demo_account_username"),
											  configLoader.getKey("demo_account_password"),
											  configLoader.getKey("demo_account_connectiontype"));
public:
	TestSessionHandler(){}
	virtual ~TestSessionHandler(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestSessionHandler");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestSessionHandler>("Test constructor",&TestSessionHandler::testConstructor));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestSessionHandler>("Test Login Logout",&TestSessionHandler::testLoginAndLogout));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestSessionHandler>("Test ResponseListener",&TestSessionHandler::testResponseListener));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "SessionHandler:\t\t" <<  __func__ << std::endl;
		SessionHandler testSession(demoLoginParams);
		CPPUNIT_ASSERT(testSession.isConnected() == false);
	}

	void testLoginAndLogout() {
		std::cerr << "SessionHandler:\t\t" <<  __func__ << std::endl;

		GlobalFXCMConnection::Instance()->getSessionHandler()->login();
		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->isConnected());

		GlobalFXCMConnection::Instance()->getSessionHandler()->logout();
		CPPUNIT_ASSERT(!GlobalFXCMConnection::Instance()->getSessionHandler()->isConnected());

		GlobalFXCMConnection::Instance()->getSessionHandler()->login();
		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->isConnected());

	}

	void testResponseListener() {
		std::cerr << "SessionHandler:\t\t" <<  __func__ << std::endl;
		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->isConnected());
		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->getResponseListener() == 0);

		CPPUNIT_ASSERT_NO_THROW(GlobalFXCMConnection::Instance()->getSessionHandler()->attachResponseListener());

		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->getResponseListener() != 0);

		CPPUNIT_ASSERT_NO_THROW(GlobalFXCMConnection::Instance()->getSessionHandler()->releaseResponseListener());
		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->getResponseListener() == 0);
	}
};



#endif /* TESTSESSIONHANDLER_H_ */
