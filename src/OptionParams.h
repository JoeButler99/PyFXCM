/*
 * OptionParams.h
 *
 *  Created on: 17 Oct 2014
 *      Author: joe
 */

#pragma once
#include "stdafx.h"


class OptionParams {
public:
	OptionParams();
	virtual ~OptionParams();

	DATE getDateFrom() const;
	void setDateFrom(std::string isoDateFrom);
	DATE getDateTo() const;
	void setDateTo(std::string isoDateFrom);

	const std::string& getAccount() const {
		return mAccount;
	}

	void setAccount(const std::string& account) {
		mAccount = account;
	}

	const std::string& getBuySell() const {
		return mBuySell;
	}

	void setBuySell(const std::string& buySell) {
		mBuySell = buySell;
	}

	const std::string& getContingencyId() const {
		return mContingencyID;
	}

	void setContingencyId(const std::string& contingencyId) {
		mContingencyID = contingencyId;
	}

	const std::string& getExpDate() const {
		return mExpDate;
	}

	void setExpDate(const std::string& expDate) {
		mExpDate = expDate;
	}

	const std::string& getInstrument() const {
		return mInstrument;
	}

	void setInstrument(const std::string& instrument) {
		mInstrument = instrument;
	}

	int getLots() const {
		return mLots;
	}

	void setLots(int lots) {
		mLots = lots;
	}

	const std::string& getOrderId() const {
		return mOrderID;
	}

	void setOrderId(const std::string& orderId) {
		mOrderID = orderId;
	}

	const std::string& getOrderType() const {
		return mOrderType;
	}

	void setOrderType(const std::string& orderType) {
		mOrderType = orderType;
	}

	const std::string& getPrimaryId() const {
		return mPrimaryID;
	}

	void setPrimaryId(const std::string& primaryId) {
		mPrimaryID = primaryId;
	}

	double getRate() const {
		return mRate;
	}

	void setRate(double rate) {
		mRate = rate;
	}

	double getRateLimit() const {
		return mRateLimit;
	}

	void setRateLimit(double rateLimit) {
		mRateLimit = rateLimit;
	}

	double getRateStop() const {
		return mRateStop;
	}

	void setRateStop(double rateStop) {
		mRateStop = rateStop;
	}

	const std::string& getSecondaryId() const {
		return mSecondaryID;
	}

	void setSecondaryId(const std::string& secondaryId) {
		mSecondaryID = secondaryId;
	}

	const std::string& getStatus() const {
		return mStatus;
	}

	void setStatus(const std::string& status) {
		mStatus = status;
	}

	const std::string& getTimeframe() const {
		return mTimeframe;
	}

	void setTimeframe(const std::string& timeframe) {
		mTimeframe = timeframe;
	}

private:
    std::string mInstrument;
    std::string mBuySell;
    std::string mContingencyID;
    std::string mOrderID;
    std::string mPrimaryID;
    std::string mSecondaryID;
    std::string mTimeframe;
    std::string mAccount;
    std::string mOrderType;
    std::string mStatus;
    std::string mExpDate;
    std::string dateStringFormat = "%Y-%m-%dT%H:%M:%S";
    int mLots;
    DATE mDateFrom;
    DATE mDateTo;
    double mRate;
    double mRateStop;
    double mRateLimit;
};
