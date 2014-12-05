/*
 * TestOptionParams.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTOPTIONPARAMS_H_
#define TESTOPTIONPARAMS_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/OptionParams.h"

class TestOptionParams : public CppUnit::TestFixture {
public:
	TestOptionParams(){}
	virtual ~TestOptionParams(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestOptionParams");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestOptionParams>("Test constructor",&TestOptionParams::testConstructor));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestOptionParams>("Test Getters and Setters",&TestOptionParams::testGettersAndSetters));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestOptionParams>("Test Invalid Timeframes",&TestOptionParams::testInvalidTimeframes));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "OptionParams:\t\t" <<  __func__ << std::endl;
		OptionParams op;
		CPPUNIT_ASSERT(op.getInstrument() == "");
		CPPUNIT_ASSERT(op.getBuySell() == "");
		CPPUNIT_ASSERT(op.getContingencyId() == "");
		CPPUNIT_ASSERT(op.getOrderId() == "");
		CPPUNIT_ASSERT(op.getPrimaryId() == "");
		CPPUNIT_ASSERT(op.getSecondaryId() == "");
		CPPUNIT_ASSERT(op.getTimeframe() == "");
		CPPUNIT_ASSERT(op.getAccount() == "");
		CPPUNIT_ASSERT(op.getOrderType() == "");
		CPPUNIT_ASSERT(op.getStatus() == "");
		CPPUNIT_ASSERT(op.getExpDate() == "");
		CPPUNIT_ASSERT(op.getLots() == 0);
		CPPUNIT_ASSERT(isnan(op.getDateFrom()));
		CPPUNIT_ASSERT(isnan(op.getDateTo()));
		CPPUNIT_ASSERT(op.getRate() == 0);
		CPPUNIT_ASSERT(op.getRateStop() == 0);
		CPPUNIT_ASSERT(op.getRateLimit() == 0);
	}

	void testGettersAndSetters() {
		std::cerr << "OptionParams:\t\t" <<  __func__ << std::endl;
		OptionParams op;

		op.setInstrument("EUR/USD");
		op.setBuySell("BUY");
		op.setContingencyId("1234");
		op.setOrderId("9876");
		op.setPrimaryId("5678");
		op.setSecondaryId("8765");
		op.setTimeframe("H1");
		op.setAccount("1111");
		op.setOrderType("MARKET");
		op.setStatus("LIVE");
		op.setExpDate("25");
		op.setLots(10);
		op.setDateFrom("2007-03-04T21:08:12");
		op.setDateTo("2008-03-04T21:08:12");
		op.setRate(1.0);
		op.setRateStop(0.9);
		op.setRateLimit(1.1);


		CPPUNIT_ASSERT(op.getInstrument() == "EUR/USD");
		CPPUNIT_ASSERT(op.getBuySell() == "BUY");
		CPPUNIT_ASSERT(op.getContingencyId() == "1234");
		CPPUNIT_ASSERT(op.getOrderId() == "9876");
		CPPUNIT_ASSERT(op.getPrimaryId() == "5678");
		CPPUNIT_ASSERT(op.getSecondaryId() == "8765");
		CPPUNIT_ASSERT(op.getTimeframe() == "H1");
		CPPUNIT_ASSERT(op.getAccount() == "1111");
		CPPUNIT_ASSERT(op.getOrderType() == "MARKET");
		CPPUNIT_ASSERT(op.getStatus() == "LIVE");
		CPPUNIT_ASSERT(op.getExpDate() == "25");
		CPPUNIT_ASSERT(op.getLots() == 10);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(39145.880694444,op.getDateFrom(),0.00001);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(39511.880694444,op.getDateTo(),0.00001);
		CPPUNIT_ASSERT(op.getRate() == 1.0);
		CPPUNIT_ASSERT(op.getRateStop() == 0.9);
		CPPUNIT_ASSERT(op.getRateLimit() == 1.1);
	}


	void testInvalidTimeframes() {
		std::cerr << "OptionParams:\t\t" <<  __func__ << std::endl;
		OptionParams op;
		op.setTimeframe("m17");
		CPPUNIT_ASSERT(op.getTimeframe() == "");
		op.setTimeframe("H1");
		CPPUNIT_ASSERT(op.getTimeframe() == "H1");
		op.setTimeframe("m5");
		CPPUNIT_ASSERT(op.getTimeframe() == "m5");
		op.setTimeframe("blahblahblah");
		CPPUNIT_ASSERT(op.getTimeframe() == "");
	}
};



#endif /* TESTOPTIONPARAMS_H_ */
