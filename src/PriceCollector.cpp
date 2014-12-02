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
	return false;
}

bool PriceCollector::collectData() {
	return false;
}
