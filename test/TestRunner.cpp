/*

    Copyright (C) 2013-2014 Joe Butler
    This file is part of Thoth.

    Thoth is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Thoth is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Thoth.  If not, see <http://www.gnu.org/licenses/>.

*/


#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <stdio.h>

// Get the test classes
#include "TestFXCMAPIException.h"
#include "TestYamlConfigLoader.h"
#include "TestPriceDataRecord.h"
#include "TestLoginParams.h"
#include "TestOptionParams.h"
#include "TestSessionHandler.h"
#include "TestPriceCollector.h"


int main(int argc, char **argv) {


    std::cout << "Creating Test Suites:" << std::endl;
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestResultCollector result;



    runner.addTest(TestSessionHandler::suite());
    runner.addTest(TestFXCMAPIException::suite());
    runner.addTest(TestYamlConfigLoader::suite());
    runner.addTest(TestPriceDataRecord::suite());
    runner.addTest(TestLoginParams::suite());
    runner.addTest(TestOptionParams::suite());

    runner.addTest(TestPriceCollector::suite());


    std::cout<< "Running the unit tests."<< std::endl;
    runner.run("",false,true,false);

    GlobalFXCMConnection::Instance()->getSessionHandler()->logout();

    return runner.result().wasSuccessful() ? 0 : 1;
}
