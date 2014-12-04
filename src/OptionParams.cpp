/*
 * OptionParams.cpp
 *
 *  Created on: 17 Oct 2014
 *      Author: joe
 */

#include "OptionParams.h"

const std::set<std::string> OptionParams::sValidTimeFrames {"Tick","m1","m5","m15","m30","H1","H4","D1","W1"};

OptionParams::OptionParams()
 :mInstrument(""), mBuySell(""), mContingencyID(""), mOrderID(""), mPrimaryID(""),
  mSecondaryID(""), mTimeframe(""),  mAccount(""), mOrderType(""), mStatus(""), mExpDate(""),
  mLots(0), mDateEarliest(NaN),  mDateLatest(NaN), mRate(0), mRateStop(0), mRateLimit(0)
{ }

OptionParams::~OptionParams() {}




DATE OptionParams::getDateFrom() const {
	return mDateEarliest;
}

void OptionParams::setDateFrom(std::string isoDateFrom) {
	struct tm tmBuf = {0};

	if (isoDateFrom.empty()) {
		mDateEarliest = NaN;
	} else {
		// TODO - Throw FXCMExceptions for bad dates
		strptime(isoDateFrom.c_str(),dateStringFormat.c_str(),&tmBuf);
		CO2GDateUtils::CTimeToOleTime(&tmBuf, &mDateEarliest);
	}

}

DATE OptionParams::getDateTo() const {
	return mDateLatest;
}

void OptionParams::setDateTo(std::string isoDateTo) {
	struct tm tmBuf = {0};

	if (isoDateTo.empty()) {
		mDateLatest = NaN;
	} else {
		// TODO - Throw FXCMExceptions for bad dates
		strptime(isoDateTo.c_str(),dateStringFormat.c_str(),&tmBuf);
		CO2GDateUtils::CTimeToOleTime(&tmBuf, &mDateLatest);
	}
}

void OptionParams::setTimeframe(const std::string& timeframe) {
	if (sValidTimeFrames.find(timeframe) != sValidTimeFrames.end()) {
		mTimeframe = timeframe;
	} else {
		Helpers::debugText("Could not set timeframe to: " + timeframe);
	}

}
