/*
 * Timeframe.cpp
 *
 *  Created on: 30 Oct 2014
 *      Author: joe
 */

#include "Timeframe.h"

Timeframe::~Timeframe() {}

Timeframe::Timeframe(PERIOD p) : mChosenPeriod(p) {}

const std::string Timeframe::getChosenTimeframeString() const {

	switch( mChosenPeriod) {
	case Tick:
		return "Tick";
	case m1:
		return "m1";
	case m5:
		return "m5";
	case m15:
		return "m15";
	case m30:
		return "m30";
	case H1:
		return "H1";
	case H4:
		return "H4";
	case D1:
		return "D1";
	case W1:
		return "W1";
	}
	return "H1";
}

const Timeframe::PERIOD Timeframe::getChosenTimeframe() const {
	return mChosenPeriod;
}
