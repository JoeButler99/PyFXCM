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
	mDataRecords.clear();
	// Make sure we have valid options
	if (!hasValidOptions()) { Helpers::debugText("Invalid options to collectData",true); }

	// Make sure we are connected
	if (mSessionHandler.login()) {
		Helpers::debugText("Attach Response Listener");
		mSessionHandler.attachResponseListener();

		O2G2Ptr<IO2GRequestFactory> factory = mSessionHandler.getSession()->getRequestFactory();
		if (!factory) { Helpers::debugText("Failed to get request factory",true); }

		// Find timeframe
	    O2G2Ptr<IO2GTimeframeCollection> timeframeCollection = factory->getTimeFrameCollection();
	    O2G2Ptr<IO2GTimeframe> timeframe = timeframeCollection->get(mOptionParams.getTimeframe().c_str());
	    if (!timeframe) { Helpers::debugText("Could not find timeframe: " + mOptionParams.getTimeframe(),true ); }

	    O2G2Ptr<IO2GRequest> request = factory->createMarketDataSnapshotRequestInstrument(mOptionParams.getInstrument().c_str(), timeframe, timeframe->getQueryDepth());
	    DATE dtLatest = mOptionParams.getDateTo();
	    // Make the request and handle the response
	    do {
	    	factory->fillMarketDataSnapshotRequestTime(request,mOptionParams.getDateFrom(),dtLatest,false);
	    	mSessionHandler.getResponseListener()->setRequestID(request->getRequestID());
	    	mSessionHandler.getSession()->sendRequest(request);
	    	if (!mSessionHandler.getResponseListener()->waitEvents()) { Helpers::debugText("Timeout waiting for collectData results",true); }

	    	// shift "to" bound to oldest datetime of returned data
	    	O2G2Ptr<IO2GResponse> response = mSessionHandler.getResponseListener()->getResponse();
	    	if (response && response->getType() == MarketDataSnapshot) {
	    		O2G2Ptr<IO2GResponseReaderFactory> readerFactory = mSessionHandler.getSession()->getResponseReaderFactory();
	    		if (readerFactory) {
	    			O2G2Ptr<IO2GMarketDataSnapshotResponseReader> reader = readerFactory->createMarketDataSnapshotReader(response);
	    			if (reader->size() > 0) {
	    				if(abs(dtLatest - reader->getDate(0)) > 0.0001) {
	    					dtLatest = reader->getDate(0); // earliest datetime of returned data
	    				} else { break; }
	    			}
	    		}
	    		assignDataRecords(mSessionHandler.getSession(),response);
	    	} else {
	    		break;
	    	}

	    } while (dtLatest - mOptionParams.getDateFrom() > 0.0001);
		mSessionHandler.releaseResponseListener();
		Helpers::debugText("Release Response Listener");
		// reverse the vector which is currently newest to oldest
		std::reverse(std::begin(mDataRecords), std::end(mDataRecords));

		return true;
	} else {
		Helpers::debugText("Connection attempt failed",true);
	}
	return false;
}


void PriceCollector::assignDataRecords(IO2GSession *session, IO2GResponse *response) {
	O2G2Ptr<IO2GResponseReaderFactory> factory = session->getResponseReaderFactory();
	if (factory) {
		O2G2Ptr<IO2GMarketDataSnapshotResponseReader> reader = factory->createMarketDataSnapshotReader(response);
		if (reader) {
			for (int ii = reader->size() - 1; ii >= 0; ii--) {
				if (reader->isBar()) {
					if (mDataRecords.size() > 0 && reader->getDate(ii) == mDataRecords.back().getStartTime()) {
						// Duplicate record here
					} else {
						mDataRecords.push_back(PriceDataRecord(mOptionParams.getInstrument(),
															   reader->getDate(ii),
															   mOptionParams.getTimeframe(),
															   reader->getBidOpen(ii),
															   reader->getBidHigh(ii),
															   reader->getBidLow(ii),
															   reader->getBidClose(ii),
															   reader->getAskOpen(ii),
															   reader->getAskHigh(ii),
															   reader->getAskLow(ii),
															   reader->getAskClose(ii)));
					}
				}
			}
		}
	}
}
