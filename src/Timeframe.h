/*
 * Timeframe.h
 *
 *  Created on: 30 Oct 2014
 *      Author: joe
 */

#ifndef TIMEFRAME_H_
#define TIMEFRAME_H_
#include "stdafx.h"

class Timeframe {
public:
	enum PERIOD {
		Tick = 0,
		m1	 = 1,
		m5   = 2,
		m15  = 3,
		m30  = 4,
		H1	 = 5,
		H4	 = 6,
		D1	 = 7,
		W1	 = 8
	};
	Timeframe(PERIOD p);
	virtual ~Timeframe();
	const std::string getChosenTimeframeString() const ;
	const Timeframe::PERIOD getChosenTimeframe() const ;
private:
	const PERIOD mChosenPeriod;
};

#endif /* TIMEFRAME_H_ */
