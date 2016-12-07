

#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/Response.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/SearchDescription.hpp"
#include "mlclient/NoCredentialsException.hpp"

#include "PathNavigatorTest.hpp"
#include "mlclient/utilities/PathNavigator.hpp"
#include "mlclient/utilities/PugiXmlHelper.hpp"
#include "mlclient/utilities/PugiXmlDocumentContent.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
#include "mlclient/ext/pugixml/pugixml.hpp"


#include "mlclient/logging.hpp"

using namespace mlclient;
using namespace mlclient::utilities;

CPPUNIT_TEST_SUITE_REGISTRATION(PathNavigatorTest);

void PathNavigatorTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE PathNavigatorTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void PathNavigatorTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE PathNavigatorTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void PathNavigatorTest::testXmlPath() {
  TIMED_FUNC(testAll);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering PathNavigatorTest::testXmlPath";

  // create XML Document

  std::string raw = "<root><el1>val1</el1><el2>val2</el2><el3>1234</el3><el4>true</el4><el5>123.456</el5><arr1>av1</arr1><arr1>av2</arr1><obj1><subel1>subval1</subel1></obj1></root>";

  std::unique_ptr<pugi::xml_document> val = mlclient::make_unique<pugi::xml_document>();
  pugi::xml_parse_result result = val->load_string(raw.c_str());

  ITextDocumentContent* doc = mlclient::utilities::PugiXmlHelper::toDocument(std::move(val));
  CPPUNIT_ASSERT_MESSAGE("XML document is null",nullptr != doc);

  // 1. Test path with child to true
  // Evaluate navigator path at top level
  IDocumentNavigator* nav = doc->navigate(true);
  CPPUNIT_ASSERT_MESSAGE("Navigator is null",nullptr != nav);
  IDocumentNode* subel1 = mlclient::utilities::PathNavigator::navigate(nav,"obj1/subel1");
  CPPUNIT_ASSERT_MESSAGE("PathNavigator::navigate->obj1/subel1 is null",nullptr != subel1);
  std::string val1 = subel1->asString();
  CPPUNIT_ASSERT_MESSAGE("subel1 string from nav is null", ""!=val1);
  // Evaluate immediate child, using at
  IDocumentNode* child = nav->at("obj1");
  CPPUNIT_ASSERT_MESSAGE("first child is null",nullptr != child);
  IDocumentNode* subelAgain = mlclient::utilities::PathNavigator::at(child,"subel1");
  CPPUNIT_ASSERT_MESSAGE("PathNavigator::at->subel1 is null",nullptr != subelAgain);
  std::string val2 = subelAgain->asString();
  CPPUNIT_ASSERT_MESSAGE("subel1 string from at is null","" !=val2);


};

void PathNavigatorTest::testJsonPath() {
  TIMED_FUNC(testJsonPath);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering PathNavigatorTest::testJsonPath";

  // create XML Document

  std::string raw = "{\"el1\":\"val1\",\"el2\":\"val2\",\"el3\":1234,\"el4\":\"true\",\"el5\":123.456,\"arr1\": [\"av1\",\"av2\"],\"obj1\":{\"subel1\":\"subval1\"}}";

  web::json::value val = web::json::value::parse(utility::conversions::to_string_t(raw));

  ITextDocumentContent* doc = mlclient::utilities::CppRestJsonHelper::toDocument(val);
  CPPUNIT_ASSERT_MESSAGE("XML document is null",nullptr != doc);

  // 1. Test path with child to true
  // Evaluate navigator path at top level
  IDocumentNavigator* nav = doc->navigate(true);
  CPPUNIT_ASSERT_MESSAGE("Navigator is null",nullptr != nav);
  IDocumentNode* subel1 = mlclient::utilities::PathNavigator::navigate(nav,"obj1/subel1");
  CPPUNIT_ASSERT_MESSAGE("PathNavigator::navigate->obj1/subel1 is null",nullptr != subel1);
  std::string val1 = subel1->asString();
  CPPUNIT_ASSERT_MESSAGE("subel1 string from nav is null", ""!=val1);
  // Evaluate immediate child, using at
  IDocumentNode* child = nav->at("obj1");
  CPPUNIT_ASSERT_MESSAGE("first child is null",nullptr != child);
  IDocumentNode* subelAgain = mlclient::utilities::PathNavigator::at(child,"subel1");
  CPPUNIT_ASSERT_MESSAGE("PathNavigator::at->subel1 is null",nullptr != subelAgain);
  std::string val2 = subelAgain->asString();
  CPPUNIT_ASSERT_MESSAGE("subel1 string from at is null","" !=val2);


};

void PathNavigatorTest::testJsonPathExtended() {
  TIMED_FUNC(testJsonPathExtended);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering PathNavigatorTest::testJsonPathExtended";

  // create XML Document

  std::string raw = "{\"claim\":{\"diagnoses\":{\"diagnosis\":[{\"code\":\"value\"},{\"code\":\"otherval\"}]}}}";
  web::json::value val = web::json::value::parse(utility::conversions::to_string_t(raw));

  ITextDocumentContent* doc = mlclient::utilities::CppRestJsonHelper::toDocument(val);
  CPPUNIT_ASSERT_MESSAGE("XML document is null",nullptr != doc);

  // 1. Test path with child to true
  // Evaluate navigator path at top level
  IDocumentNavigator* nav = doc->navigate(true);
  CPPUNIT_ASSERT_MESSAGE("Navigator is null",nullptr != nav);
  IDocumentNode* subel1 = mlclient::utilities::PathNavigator::navigate(nav,"diagnoses/diagnosis/code");
  CPPUNIT_ASSERT_MESSAGE("PathNavigator::navigate->diagnoses/diagnosis/code is null",nullptr != subel1);
  std::string val1 = subel1->asString();
  CPPUNIT_ASSERT_MESSAGE("subel1 string from nav is null", ""!=val1);
  // Evaluate immediate child, using at
  IDocumentNode* child = nav->at("obj1");
  CPPUNIT_ASSERT_MESSAGE("first child is null",nullptr != child);
  IDocumentNode* subelAgain = mlclient::utilities::PathNavigator::at(child,"diagnosis/code");
  CPPUNIT_ASSERT_MESSAGE("PathNavigator::at->subel1 is null",nullptr != subelAgain);
  std::string val2 = subelAgain->asString();
  CPPUNIT_ASSERT_MESSAGE("subel1 string from at is null","" !=val2);


};