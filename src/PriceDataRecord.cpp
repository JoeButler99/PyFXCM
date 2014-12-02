/*
 * PriceDataRecord.cpp
 *
 *  Created on: 30 Oct 2014
 *      Author: joe
 */

#include "PriceDataRecord.h"

PriceDataRecord::PriceDataRecord(std::string instrument, DATE startTime,
		Timeframe timeframe, double bidOpen, double bidHigh, double bidLow,
		double bidClose, double askOpen, double askHigh, double askLow,
		double askClose)
: mInstrument(instrument), mStartTime(startTime), mTimeframe(timeframe),
  mBidOpen(bidOpen), mBidHigh(bidHigh), mBidLow(bidLow), mBidClose(bidClose),
  mAskOpen(askOpen), mAskHigh(askHigh), mAskLow(askLow), mAskClose(askClose)
{}

PriceDataRecord::~PriceDataRecord() {}

void PriceDataRecord::displayInConsole() {
}
