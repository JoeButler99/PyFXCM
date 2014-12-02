#pragma once
#include "stdafx.h"
#include "Timeframe.h"
/*
 * PriceDataRecord.h
 *
 *  Created on: 30 Oct 2014
 *      Author: joe
 */


class PriceDataRecord {
private:
	const std::string mInstrument;
	const DATE mStartTime;
	const Timeframe mTimeframe;
	const double mBidOpen, mBidHigh, mBidLow, mBidClose;
	const double mAskOpen, mAskHigh, mAskLow, mAskClose;

public:
	PriceDataRecord(std::string instrument, DATE startTime, Timeframe timeframe,
					double bidOpen, double bidHigh, double bidLow, double bidClose,
					double askOpen, double askHigh, double askLow, double askClose);
	virtual ~PriceDataRecord();
	void displayInConsole();

	const double getAskClose() const {
		return mAskClose;
	}

	const double getAskHigh() const {
		return mAskHigh;
	}

	const double getAskLow() const {
		return mAskLow;
	}

	const double getAskOpen() const {
		return mAskOpen;
	}

	const double getBidClose() const {
		return mBidClose;
	}

	const double getBidHigh() const {
		return mBidHigh;
	}

	const double getBidLow() const {
		return mBidLow;
	}

	const double getBidOpen() const {
		return mBidOpen;
	}

	const std::string& getInstrument() const {
		return mInstrument;
	}

	const DATE getStartTime() const {
		return mStartTime;
	}

	const Timeframe& getTimeframe() const {
		return mTimeframe;
	}
};

