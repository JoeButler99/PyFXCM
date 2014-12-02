/*
 * TestTimeframe.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTTIMEFRAME_H_
#define TESTTIMEFRAME_H_
// TODO - Pick pragma once vs ifndef.. (All headers)

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/Timeframe.h"


class TestTimeframe : public CppUnit::TestFixture {
public:
	TestTimeframe(){}
	virtual ~TestTimeframe(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestTimeframe");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestTimeframe>("Test Timeframe",&TestTimeframe::testTimeframe));
		return suiteOfTests;
	}
protected:
	void testTimeframe() {
		std::cerr << "Timeframe:\t\t" <<  __func__ << std::endl;
		Timeframe t1(Timeframe::H1);
		Timeframe t2(Timeframe::m30);

		CPPUNIT_ASSERT(t1.getChosenTimeframeString() == "H1");
		CPPUNIT_ASSERT(t2.getChosenTimeframeString() == "m30");

		CPPUNIT_ASSERT(t1.getChosenTimeframe() == Timeframe::H1);
		CPPUNIT_ASSERT(t2.getChosenTimeframe() == Timeframe::m30);
	}
};



#endif /* TESTTIMEFRAME_H_ */
