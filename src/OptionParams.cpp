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
  mLots(0), mDateFrom(0),  mDateTo(0), mRate(0), mRateStop(0), mRateLimit(0)
{ }

OptionParams::~OptionParams() {}

