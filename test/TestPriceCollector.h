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
public:
	TestPriceCollector(){}
	virtual ~TestPriceCollector(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestPriceCollector");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test Constructor",&TestPriceCollector::testConstructor));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test validOptions",&TestPriceCollector::testHasValidOptions));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test collect data",&TestPriceCollector::testCollectData));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceCollector>("Test get data records",&TestPriceCollector::testGetDataRecords));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;
		OptionParams   options;
		options.setInstrument("EUR/USD");
		PriceCollector priceCollector = PriceCollector(*GlobalFXCMConnection::Instance()->getSessionHandler(),options);

	}

	void testHasValidOptions() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;
		OptionParams   options;
		options.setInstrument("EUR/USD");
		PriceCollector priceCollector = PriceCollector(*GlobalFXCMConnection::Instance()->getSessionHandler(),options);

		CPPUNIT_ASSERT(!priceCollector.hasValidOptions());

		OptionParams   options2;
		options2.setInstrument("EUR/USD");
		options2.setTimeframe("H1");
		options2.setDateFrom("2007-03-04T21:08:12");
		options2.setDateTo("2008-03-04T21:08:13");
		PriceCollector priceCollector2 = PriceCollector(*GlobalFXCMConnection::Instance()->getSessionHandler(),options2);
		CPPUNIT_ASSERT(priceCollector2.hasValidOptions());


		OptionParams   options3;
		options3.setInstrument("EUR/USD");
		options3.setTimeframe("H1");
		options3.setDateTo("2008-03-04T21:08:13");
		PriceCollector priceCollector3 = PriceCollector(*GlobalFXCMConnection::Instance()->getSessionHandler(),options3);
		CPPUNIT_ASSERT(!priceCollector3.hasValidOptions());

	}

	void testCollectData() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;

		CPPUNIT_ASSERT(GlobalFXCMConnection::Instance()->getSessionHandler()->isConnected());
		OptionParams   options;
		options.setInstrument("EUR/USD");
		options.setTimeframe("H1");
		options.setDateFrom("2014-01-01T00:00:00");
		options.setDateTo("2014-02-01T00:00:00");

		PriceCollector priceCollector = PriceCollector(*GlobalFXCMConnection::Instance()->getSessionHandler(),options);

		CPPUNIT_ASSERT(priceCollector.hasValidOptions());
		CPPUNIT_ASSERT(priceCollector.getDataRecords().size() == 0);
		CPPUNIT_ASSERT(priceCollector.collectData());
		CPPUNIT_ASSERT(priceCollector.getDataRecords().size() > 0);
	}

	void testGetDataRecords() {
		std::cerr << "PriceCollector:\t" <<  __func__ << std::endl;
		OptionParams   options;
		options.setInstrument("EUR/USD");
		options.setTimeframe("H1");
		options.setDateFrom("2014-01-01T00:00:00");
		options.setDateTo("2014-02-01T00:00:00");

		PriceCollector priceCollector = PriceCollector(*GlobalFXCMConnection::Instance()->getSessionHandler(),options);
		CPPUNIT_ASSERT(priceCollector.hasValidOptions());
		CPPUNIT_ASSERT(priceCollector.getDataRecords().size() == 0);
		CPPUNIT_ASSERT(priceCollector.collectData());
		CPPUNIT_ASSERT(priceCollector.getDataRecords().size() > 300);
		bool first = true;
		double startTime = 0;
		for (unsigned int i = 0; i < priceCollector.getDataRecords().size(); i ++) {
			const PriceDataRecord & pdr = priceCollector.getDataRecords().at(i);
			if (first) {
				first = false;
				startTime = pdr.getStartTime();
			} else {
				// Check the records go in order
				CPPUNIT_ASSERT(pdr.getStartTime() > startTime);
				startTime = pdr.getStartTime();
			}
			CPPUNIT_ASSERT(pdr.getTimeframe() == "H1");
			CPPUNIT_ASSERT(pdr.getAskHigh() >= pdr.getAskLow());
			CPPUNIT_ASSERT(pdr.getBidHigh() >= pdr.getBidLow());
			CPPUNIT_ASSERT(pdr.getInstrument() == "EUR/USD");
		}


	}
};



#endif /* TESTPRICECOLLECTOR_H_ */

