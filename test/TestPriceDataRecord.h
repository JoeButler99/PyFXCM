/*
 * TestPriceDataRecord.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTPRICEDATARECORD_H_
#define TESTPRICEDATARECORD_H_
// TODO - Pick pragma once vs ifndef.. (All headers)

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/PriceDataRecord.h"


class TestPriceDataRecord : public CppUnit::TestFixture {
public:
	TestPriceDataRecord(){}
	virtual ~TestPriceDataRecord(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestPriceDataRecord");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestPriceDataRecord>("Test PriceDataRecord",&TestPriceDataRecord::testConstructor));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "PriceDataRecord:\t" <<  __func__ << std::endl;
		// TODO - Need to check the right date format, EPOCH in microseconds??
		DATE startTime(1414645200000);
		const Timeframe t(Timeframe::H1);

		PriceDataRecord pdr1("EUR/USD",startTime,t,1.0,1.1,0.9,1.05,1.0,1.1,0.9,1.05);

		CPPUNIT_ASSERT(pdr1.getInstrument() == "EUR/USD");
		CPPUNIT_ASSERT(pdr1.getStartTime() == startTime);
		CPPUNIT_ASSERT(pdr1.getTimeframe().getChosenTimeframe() == Timeframe::H1 );
		CPPUNIT_ASSERT(pdr1.getBidOpen() == 1.0);
		CPPUNIT_ASSERT(pdr1.getBidHigh() == 1.1);
		CPPUNIT_ASSERT(pdr1.getBidLow() == 0.9);
		CPPUNIT_ASSERT(pdr1.getBidClose() == 1.05);
		CPPUNIT_ASSERT(pdr1.getAskOpen() == 1.0);
		CPPUNIT_ASSERT(pdr1.getAskHigh() == 1.1);
		CPPUNIT_ASSERT(pdr1.getAskLow() == 0.9);
		CPPUNIT_ASSERT(pdr1.getAskClose() == 1.05);
	}
};



#endif /* TESTPRICEDATARECORD_H_ */

