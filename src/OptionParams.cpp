/*
 * OptionParams.cpp
 *
 *  Created on: 17 Oct 2014
 *      Author: joe
 */

#include "OptionParams.h"

OptionParams::OptionParams()
 :mInstrument(""), mBuySell(""), mContingencyID(""), mOrderID(""), mPrimaryID(""),
  mSecondaryID(""), mTimeframe(""),  mAccount(""), mOrderType(""), mStatus(""), mExpDate(""),
  mLots(0), mDateFrom(NaN),  mDateTo(NaN), mRate(0), mRateStop(0), mRateLimit(0)
{ }

OptionParams::~OptionParams() {}




DATE OptionParams::getDateFrom() const {
	return mDateFrom;
}

void OptionParams::setDateFrom(std::string isoDateFrom) {
	struct tm tmBuf = {0};

	if (isoDateFrom.empty()) {
		mDateFrom = NaN;
	} else {
		// TODO - Throw FXCMExceptions for bad dates
		strptime(isoDateFrom.c_str(),dateStringFormat.c_str(),&tmBuf);
		CO2GDateUtils::CTimeToOleTime(&tmBuf, &mDateFrom);
	}

}

DATE OptionParams::getDateTo() const {
	return mDateTo;
}

void OptionParams::setDateTo(std::string isoDateTo) {
	struct tm tmBuf = {0};

	if (isoDateTo.empty()) {
		mDateTo = NaN;
	} else {
		// TODO - Throw FXCMExceptions for bad dates
		strptime(isoDateTo.c_str(),dateStringFormat.c_str(),&tmBuf);
		CO2GDateUtils::CTimeToOleTime(&tmBuf, &mDateTo);
	}
}
