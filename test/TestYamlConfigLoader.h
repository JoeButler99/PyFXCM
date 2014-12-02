/*
 * TestYamlConfigLoader.h
 *
 *  Created on: 28 Sep 2014
 *      Author: joe
 */

#ifndef TESTYAMLCONFIGLOADER_H_
#define TESTYAMLCONFIGLOADER_H_

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>
#include "../src/stdafx.h"
#include "../src/YamlConfigLoader.h"


class TestYamlConfigLoader : public CppUnit::TestFixture {
private:
	// TODO
public:
	TestYamlConfigLoader(){}
	virtual ~TestYamlConfigLoader(){}

	static CppUnit::Test *suite() {
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestYamlConfigLoader");
		suiteOfTests->addTest(new CppUnit::TestCaller<TestYamlConfigLoader>("Test constructor",&TestYamlConfigLoader::testConstructor));
		suiteOfTests->addTest(new CppUnit::TestCaller<TestYamlConfigLoader>("Test constructor",&TestYamlConfigLoader::testGetValues));
		return suiteOfTests;
	}
protected:
	void testConstructor() {
		std::cerr << "YamlConfigLoader:\t" <<  __func__ << std::endl;
		CPPUNIT_ASSERT_NO_THROW(YamlConfigLoader configLoader = YamlConfigLoader("config/config.yaml"));
	}


	void testGetValues() {
		std::cerr << "YamlConfigLoader:\t" <<  __func__ << std::endl;
		// TODO - Can't think of how to test exact values without hard coding

		// Check good file good key
		YamlConfigLoader configLoader = YamlConfigLoader("config/config.yaml");
		std::cerr << "YamlConfigLoader:\t" <<  __func__ << std::endl;
		CPPUNIT_ASSERT(!configLoader.getKey("demo_account_username").empty());
		std::cerr << "YamlConfigLoader:\t" <<  __func__ << std::endl;
		CPPUNIT_ASSERT(!configLoader.getKey("demo_account_password").empty());
		CPPUNIT_ASSERT(configLoader.getKey("demo_account_connectiontype") == "Demo");
		CPPUNIT_ASSERT(!configLoader.getKey("real_account_username").empty());
		CPPUNIT_ASSERT(!configLoader.getKey("real_account_password").empty());
		CPPUNIT_ASSERT(configLoader.getKey("real_account_connectiontype") == "Real");

		std::cerr << "YamlConfigLoader:\t" <<  __func__ << std::endl;
		// Check good file bad key
		configLoader = YamlConfigLoader("config/config.yaml");
		CPPUNIT_ASSERT(configLoader.getKey("something_non_existant").empty());
		CPPUNIT_ASSERT(configLoader.getKey("something_non_existant2").empty());

		std::cerr << "YamlConfigLoader:\t" <<  __func__ << std::endl;
		// Check bad file
		configLoader = YamlConfigLoader("config/config.yaml.madeupexamplewhichiswrong");
		CPPUNIT_ASSERT_THROW(configLoader.getKey("MadeUpKey"),FXCMAPIException);

	}
};



#endif /* TESTYAMLCONFIGLOADER_H_ */
