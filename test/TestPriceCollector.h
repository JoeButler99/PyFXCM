/*
 * TestPriceCollector.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTPRICECOLLECTOR_H_
#define TESTPRICECOLLECTOR_H_
// TODO - Pick pragma once vs ifndef.. (All headers)

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/PriceCollector.h"
#include "../src/SessionHandler.h"
#include "../src/OptionParams.h"


class TestPriceCollector : public CppUnit::TestFixture {
private:
	YamlConfigLoader configLoader = YamlConfigLoader("config/config.yaml");
	LoginParams demoLoginParams = LoginParams(configLoader.getKey("demo_account_username"),
											  configLoader.getKey("demo_account_password"),
											  configLoader.getKey("demo_account_connectiontype"));

	LoginParams realLoginParams = LoginParams(configLoader.getKey("real_account_username"),
												  configLoader.getKey("real_account_password"),
												  configLoader.getKey("real_account_connectiontype"));
public:
	TestPriceCollector(){}
	virtual ~TestPriceCollector(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestPriceCollector");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test PriceCollector",&TestPriceCollector::testConstructor));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test PriceCollector",&TestPriceCollector::testHasValidOptions));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test PriceCollector",&TestPriceCollector::testCollectData));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;
		SessionHandler demoSession(demoLoginParams);
		OptionParams   options;
		options.setInstrument("EUR/USD");
		PriceCollector priceCollector = PriceCollector(demoSession,options);

	}

	void testHasValidOptions() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;
		CPPUNIT_ASSERT(false);
	}

	void testCollectData() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;
		CPPUNIT_ASSERT(false);
	}
};



#endif /* TESTPRICECOLLECTOR_H_ */

