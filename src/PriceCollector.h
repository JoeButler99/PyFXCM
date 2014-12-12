/*
 * PriceCollector.h
 *
 *  Created on: 30 Oct 2014
 *      Author: joe
 */

#ifndef SRC_PRICECOLLECTOR_H_
#define SRC_PRICECOLLECTOR_H_
#include "stdafx.h"
#include "OptionParams.h"
#include "PriceDataRecord.h"
#include "SessionHandler.h"
#include "Helpers.h"
#include <iterator>
#include <algorithm>

class PriceCollector {
private:
	SessionHandler & mSessionHandler;
	OptionParams   & mOptionParams;
	std::vector<PriceDataRecord> mDataRecords;
	void assignDataRecords(IO2GSession *session, IO2GResponse *response);
public:
	PriceCollector(SessionHandler & sh, OptionParams & op);
	virtual ~PriceCollector();
	bool hasValidOptions();
	bool collectData();

	const std::vector<PriceDataRecord>& getDataRecords() const {
		return mDataRecords;
	}
};

#endif /* SRC_PRICECOLLECTOR_H_ */
