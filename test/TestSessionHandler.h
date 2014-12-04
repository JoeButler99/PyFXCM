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


class TestSessionHandler : public CppUnit::TestFixture {
private:
	YamlConfigLoader configLoader = YamlConfigLoader("config/config.yaml");
	LoginParams demoLoginParams = LoginParams(configLoader.getKey("demo_account_username"),
											  configLoader.getKey("demo_account_password"),
											  configLoader.getKey("demo_account_connectiontype"));

	LoginParams realLoginParams = LoginParams(configLoader.getKey("real_account_username"),
												  configLoader.getKey("real_account_password"),
												  configLoader.getKey("real_account_connectiontype"));

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
		SessionHandler realSession(realLoginParams);
		SessionHandler demoSession(demoLoginParams);
		CPPUNIT_ASSERT(realSession.isConnected() == false);
		CPPUNIT_ASSERT(demoSession.isConnected() == false);

	}

	void testLoginAndLogout() {
		std::cerr << "SessionHandler:\t\t" <<  __func__ << std::endl;
		SessionHandler realSession(realLoginParams);
		SessionHandler demoSession(demoLoginParams);

		realSession.login();
		demoSession.login();

		CPPUNIT_ASSERT(realSession.isConnected());
		CPPUNIT_ASSERT(demoSession.isConnected());

		realSession.logout();
		demoSession.logout();
		CPPUNIT_ASSERT(!realSession.isConnected());
		CPPUNIT_ASSERT(!demoSession.isConnected());
	}

	void testResponseListener() {
		std::cerr << "SessionHandler:\t\t" <<  __func__ << std::endl;
		SessionHandler demoSession(demoLoginParams);
		demoSession.login();
		CPPUNIT_ASSERT(demoSession.isConnected());
		CPPUNIT_ASSERT_NO_THROW(demoSession.attachResponseListener());
		CPPUNIT_ASSERT_NO_THROW(demoSession.releaseResponseListener());
		demoSession.logout();
		CPPUNIT_ASSERT(!demoSession.isConnected());
	}
};



#endif /* TESTSESSIONHANDLER_H_ */
