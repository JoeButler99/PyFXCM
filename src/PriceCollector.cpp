/*
 * PriceCollector.cpp
 *
 *  Created on: 30 Oct 2014
 *      Author: joe
 */

#include "PriceCollector.h"


PriceCollector::PriceCollector(SessionHandler & sh, OptionParams & op) : mSessionHandler(sh), mOptionParams(op), mDataRecords() {}

PriceCollector::~PriceCollector() {}

bool PriceCollector::hasValidOptions() {
	if (!mOptionParams.getInstrument().empty() &&
		!mOptionParams.getTimeframe().empty()  &&
		!isnan(mOptionParams.getDateFrom())    &&
		!isnan(mOptionParams.getDateTo()) ) {
		return true;
	} else {
		return false;
	}
}

bool PriceCollector::collectData() {
	// TODO - Could this move to a general functions / tools global class
	if (!mSessionHandler.isConnected()) {
		mSessionHandler.login();
		if(!mSessionHandler.isConnected()) {
			throw FXCMAPIException("Unable to connect",1,__func__,__FILE__,__LINE__);
		}
	}


	return false;
}
