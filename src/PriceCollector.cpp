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
	// Make sure we are connected
	if (mSessionHandler.login()) {
		Helpers::debugText("Attach Response Listener");
		mSessionHandler.attachResponseListener();



		mSessionHandler.releaseResponseListener();
		Helpers::debugText("Release Response Listener");
	} else {
		Helpers::debugText("Connection attempt failed");
		throw FXCMAPIException("Unable to connect to FXCM.",1,__func__,__FILE__,__LINE__);
	}


	return false;
}
