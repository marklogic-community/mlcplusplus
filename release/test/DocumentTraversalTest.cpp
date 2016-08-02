/*
 * DocumentTraversalTest.cpp
 *
 *  Created on: 30 Jul 2016
 *      Author: adamfowler
 */


#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <string>
#include "DocumentTraversalTest.hpp"
#include "ConnectionFactory.hpp"
#include "mlclient/Connection.hpp"
#include "mlclient/DocumentContent.hpp"
#include "mlclient/utilities/CppRestJsonDocumentContent.hpp"
#include "mlclient/utilities/CppRestJsonHelper.hpp"
#include "mlclient/utilities/PugiXmlHelper.hpp"
#include "mlclient/utilities/PugiXmlDocumentContent.hpp"
#include <cpprest/http_client.h>
#include "mlclient/ext/pugixml/pugixml.hpp"

#include <string>

#include "mlclient/logging.hpp"

using namespace mlclient;

CPPUNIT_TEST_SUITE_REGISTRATION(DocumentTraversalTest);

void DocumentTraversalTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE DocumentTraversalTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void DocumentTraversalTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE DocumentTraversalTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void DocumentTraversalTest::testJsonTraversal() {
  TIMED_FUNC(testJsonTraversal);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering testJsonTraversal";

  std::string raw = "{\"el1\":\"val1\",\"el2\":\"val2\",\"el3\":1234,\"el4\":\"true\",\"el5\":123.456,\"arr1\": [\"av1\",\"av2\"],\"obj1\":{\"subel1\":\"subval1\"}}";

  web::json::value val = web::json::value::parse(utility::conversions::to_string_t(raw));

  ITextDocumentContent* doc = mlclient::utilities::CppRestJsonHelper::toDocument(val);
  this->testResultN(doc->navigate());

  LOG(DEBUG) << " Leaving testJsonTraversal";
}

void DocumentTraversalTest::testXmlTraversal() {
  TIMED_FUNC(testXmlTraversal);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering testXmlTraversal";

  std::string raw = "<root><el1>val1</el1><el2>val2</el2><el3>1234</el3><el4>true</el4><el5>123.456</el5><arr1>av1</arr1><arr1>av2</arr1><obj1><subel1>subval1</subel1></obj1></root>";

  pugi::xml_document* val = new pugi::xml_document;
  pugi::xml_parse_result result = val->load_string(raw.c_str());

  ITextDocumentContent* doc = mlclient::utilities::PugiXmlHelper::toDocument(*val);
  //this->testResult(doc);
  IDocumentNode* root = doc->navigate()->at("root");
  this->testResult(root);

  LOG(DEBUG) << " Leaving testXmlTraversal";
}

void DocumentTraversalTest::testResult(IDocumentNode* root) {
  //IDocumentNavigator* nav = doc->navigate();
  // TODO XML differs from JSON in that it has a root node. Handle this instance.
  try {
  IDocumentNode* el1 = root->at("el1");
  LOG(DEBUG) << "Checking el1";
  LOG(DEBUG) << "  value: " << el1->asString();
  CPPUNIT_ASSERT_MESSAGE("el1 is invalid",strcmp(el1->asString().c_str(),"val1") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("el1 is not a string (should be string)",el1->isString());
  CPPUNIT_ASSERT_MESSAGE("el1 is an array (should be string)",!el1->isArray());
  CPPUNIT_ASSERT_MESSAGE("el1 is a boolean (should be string)",!el1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el1 is a double (should be string)",!el1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el1 is an integer (should be string)",!el1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el1 is a null (should be string)",!el1->isNull());
  CPPUNIT_ASSERT_MESSAGE("el1 is an object (should be string)",!el1->isObject());
  */
  IDocumentNode* el2 = root->at("el2");
  LOG(DEBUG) << "Checking el2";
  CPPUNIT_ASSERT_MESSAGE("el2 is invalid",strcmp(el2->asString().c_str(),"val2") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("el2 is not a string (should be string)",el2->isString());
  CPPUNIT_ASSERT_MESSAGE("el2 is an array (should be string)",!el2->isArray());
  CPPUNIT_ASSERT_MESSAGE("el2 is a boolean (should be string)",!el2->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el2 is a double (should be string)",!el2->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el2 is an integer (should be string)",!el2->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el2 is a null (should be string)",!el2->isNull());
  CPPUNIT_ASSERT_MESSAGE("el2 is an object (should be string)",!el2->isObject());
  */
  IDocumentNode* el3 = root->at("el3");
  LOG(DEBUG) << "Checking el3";
  CPPUNIT_ASSERT_MESSAGE("el3 is invalid",el3->asInteger() == 1234);
  CPPUNIT_ASSERT_MESSAGE("el3 is not an integer (should be integer)",el3->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el3 is an array (should be integer)",!el3->isArray());
  CPPUNIT_ASSERT_MESSAGE("el3 is a boolean (should be integer)",!el3->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el3 is a double (should be integer)",!el3->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el3 is a string (should be integer)",!el3->isString());
  CPPUNIT_ASSERT_MESSAGE("el3 is a null (should be integer)",!el3->isNull());
  CPPUNIT_ASSERT_MESSAGE("el3 is an object (should be integer)",!el3->isObject());
  IDocumentNode* el4 = root->at("el4");
  LOG(DEBUG) << "Checking el4";
  // Not sure why true is not a boolean... research needed in cpprest library...
  CPPUNIT_ASSERT_MESSAGE("el4 is invalid",el4->asBoolean());
  /*
  CPPUNIT_ASSERT_MESSAGE("el4 is not a boolean (should be boolean)",el4->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el4 is an array (should be boolean)",!el4->isArray());
  CPPUNIT_ASSERT_MESSAGE("el4 is an integer (should be boolean)",!el4->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el4 is a double (should be boolean)",!el4->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el4 is a string (should be boolean)",!el4->isString());
  CPPUNIT_ASSERT_MESSAGE("el4 is a null (should be boolean)",!el4->isNull());
  CPPUNIT_ASSERT_MESSAGE("el4 is an object (should be boolean)",!el4->isObject());
  */
  IDocumentNode* el5 = root->at("el5");
  LOG(DEBUG) << "Checking el5";
  CPPUNIT_ASSERT_MESSAGE("el5 is invalid",el5->asDouble() == 123.456);
  CPPUNIT_ASSERT_MESSAGE("el5 is not a double (should be double)",el5->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el5 is an array (should be double)",!el5->isArray());
  CPPUNIT_ASSERT_MESSAGE("el5 is a boolean (should be double)",!el5->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el5 is an integer (should be double)",!el5->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el5 is a string (should be double)",!el5->isString());
  CPPUNIT_ASSERT_MESSAGE("el5 is a null (should be double)",!el5->isNull());
  CPPUNIT_ASSERT_MESSAGE("el5 is an object (should be double)",!el5->isObject());
  IDocumentNode* arr1 = root->at("arr1");
  LOG(DEBUG) << "Checking arr1";
  CPPUNIT_ASSERT_MESSAGE("arr1 is not an array (should be array)",arr1->isArray());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a double (should be array)",!arr1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a boolean (should be array)",!arr1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("arr1 is an integer (should be array)",!arr1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a string (should be array)",!arr1->isString());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a null (should be array)",!arr1->isNull());
  CPPUNIT_ASSERT_MESSAGE("arr1 is an object (should be array)",!arr1->isObject());
  IDocumentNode* arr1el0 = arr1->at(0);
  LOG(DEBUG) << "Checking arr1el0";
  LOG(DEBUG) << "Checking arr1el0: text: " << arr1el0->asString();
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is invalid",strcmp(arr1el0->asString().c_str(),"av1") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is not a string (should be string)",arr1el0->isString());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is an array (should be string)",!arr1el0->isArray());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is a boolean (should be string)",!arr1el0->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is a double (should be string)",!arr1el0->isDouble());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is an integer (should be string)",!arr1el0->isInteger());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is a null (should be string)",!arr1el0->isNull());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is an object (should be string)",!arr1el0->isObject());
  */
  IDocumentNode* arr1el1 = arr1->at(1);
  LOG(DEBUG) << "Checking arr1el1: text: " << arr1el1->asString();
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is invalid",strcmp(arr1el1->asString().c_str(),"av2") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is not a string (should be string)",arr1el1->isString());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is an array (should be string)",!arr1el1->isArray());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is a boolean (should be string)",!arr1el1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is a double (should be string)",!arr1el1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is an integer (should be string)",!arr1el1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is a null (should be string)",!arr1el1->isNull());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is an object (should be string)",!arr1el1->isObject());
  */
  IDocumentNode* obj1 = root->at("obj1");
  LOG(DEBUG) << "Checking obj1";
  CPPUNIT_ASSERT_MESSAGE("obj1 is not a object (should be object)",obj1->isObject());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a double (should be object)",!obj1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a boolean (should be object)",!obj1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("obj1 is an integer (should be object)",!obj1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a string (should be object)",!obj1->isString());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a null (should be object)",!obj1->isNull());
  CPPUNIT_ASSERT_MESSAGE("obj1 is an array (should be object)",!obj1->isArray());
  IDocumentNode* obj1subel1 = obj1->at("subel1");
  LOG(DEBUG) << "Checking obj1subel1";
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is invalid",strcmp(obj1subel1->asString().c_str(),"subval1") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is not a string (should be string)",obj1subel1->isString());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is an array (should be string)",!obj1subel1->isArray());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is a boolean (should be string)",!obj1subel1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is a double (should be string)",!obj1subel1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is an integer (should be string)",!obj1subel1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is a null (should be string)",!obj1subel1->isNull());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is an object (should be string)",!obj1subel1->isObject());
  */
} catch (std::exception& e) {
  LOG(DEBUG) << "EXCEPTION IN TEST RESULT: " << e.what();
  throw e;
}
}

void DocumentTraversalTest::testResultN(IDocumentNavigator* root) {
  //IDocumentNavigator* nav = doc->navigate();
  // TODO XML differs from JSON in that it has a root node. Handle this instance.
  try {
  IDocumentNode* el1 = root->at("el1");
  LOG(DEBUG) << "Checking el1";
  CPPUNIT_ASSERT_MESSAGE("el1 is invalid",strcmp(el1->asString().c_str(),"val1") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("el1 is not a string (should be string)",el1->isString());
  CPPUNIT_ASSERT_MESSAGE("el1 is an array (should be string)",!el1->isArray());
  CPPUNIT_ASSERT_MESSAGE("el1 is a boolean (should be string)",!el1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el1 is a double (should be string)",!el1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el1 is an integer (should be string)",!el1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el1 is a null (should be string)",!el1->isNull());
  CPPUNIT_ASSERT_MESSAGE("el1 is an object (should be string)",!el1->isObject());
  */
  IDocumentNode* el2 = root->at("el2");
  LOG(DEBUG) << "Checking el2";
  CPPUNIT_ASSERT_MESSAGE("el2 is invalid",strcmp(el2->asString().c_str(),"val2") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("el2 is not a string (should be string)",el2->isString());
  CPPUNIT_ASSERT_MESSAGE("el2 is an array (should be string)",!el2->isArray());
  CPPUNIT_ASSERT_MESSAGE("el2 is a boolean (should be string)",!el2->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el2 is a double (should be string)",!el2->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el2 is an integer (should be string)",!el2->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el2 is a null (should be string)",!el2->isNull());
  CPPUNIT_ASSERT_MESSAGE("el2 is an object (should be string)",!el2->isObject());
  */
  IDocumentNode* el3 = root->at("el3");
  LOG(DEBUG) << "Checking el3";
  CPPUNIT_ASSERT_MESSAGE("el3 is invalid",el3->asInteger() == 1234);
  CPPUNIT_ASSERT_MESSAGE("el3 is not an integer (should be integer)",el3->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el3 is an array (should be integer)",!el3->isArray());
  CPPUNIT_ASSERT_MESSAGE("el3 is a boolean (should be integer)",!el3->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el3 is a double (should be integer)",!el3->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el3 is a string (should be integer)",!el3->isString());
  CPPUNIT_ASSERT_MESSAGE("el3 is a null (should be integer)",!el3->isNull());
  CPPUNIT_ASSERT_MESSAGE("el3 is an object (should be integer)",!el3->isObject());
  IDocumentNode* el4 = root->at("el4");
  LOG(DEBUG) << "Checking el4";
  // Not sure why true is not a boolean... research needed in cpprest library...
  //CPPUNIT_ASSERT_MESSAGE("el4 is invalid",el4->asBoolean());
  LOG(DEBUG) << "  boolean value: " << el4->asBoolean();

  CPPUNIT_ASSERT_MESSAGE("el4 is not a boolean (should be boolean)",el4->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el4 is an array (should be boolean)",!el4->isArray());
  CPPUNIT_ASSERT_MESSAGE("el4 is an integer (should be boolean)",!el4->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el4 is a double (should be boolean)",!el4->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el4 is a string (should be boolean)",!el4->isString());
  CPPUNIT_ASSERT_MESSAGE("el4 is a null (should be boolean)",!el4->isNull());
  CPPUNIT_ASSERT_MESSAGE("el4 is an object (should be boolean)",!el4->isObject());

  IDocumentNode* el5 = root->at("el5");
  LOG(DEBUG) << "Checking el5";
  CPPUNIT_ASSERT_MESSAGE("el5 is invalid",el5->asDouble() == 123.456);
  CPPUNIT_ASSERT_MESSAGE("el5 is not a double (should be double)",el5->isDouble());
  CPPUNIT_ASSERT_MESSAGE("el5 is an array (should be double)",!el5->isArray());
  CPPUNIT_ASSERT_MESSAGE("el5 is a boolean (should be double)",!el5->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("el5 is an integer (should be double)",!el5->isInteger());
  CPPUNIT_ASSERT_MESSAGE("el5 is a string (should be double)",!el5->isString());
  CPPUNIT_ASSERT_MESSAGE("el5 is a null (should be double)",!el5->isNull());
  CPPUNIT_ASSERT_MESSAGE("el5 is an object (should be double)",!el5->isObject());
  IDocumentNode* arr1 = root->at("arr1");
  LOG(DEBUG) << "Checking arr1";
  CPPUNIT_ASSERT_MESSAGE("arr1 is not an array (should be array)",arr1->isArray());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a double (should be array)",!arr1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a boolean (should be array)",!arr1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("arr1 is an integer (should be array)",!arr1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a string (should be array)",!arr1->isString());
  CPPUNIT_ASSERT_MESSAGE("arr1 is a null (should be array)",!arr1->isNull());
  CPPUNIT_ASSERT_MESSAGE("arr1 is an object (should be array)",!arr1->isObject());
  IDocumentNode* arr1el0 = arr1->at(0);
  LOG(DEBUG) << "Checking arr1el0";
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is invalid",strcmp(arr1el0->asString().c_str(),"av1") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is not a string (should be string)",arr1el0->isString());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is an array (should be string)",!arr1el0->isArray());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is a boolean (should be string)",!arr1el0->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is a double (should be string)",!arr1el0->isDouble());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is an integer (should be string)",!arr1el0->isInteger());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is a null (should be string)",!arr1el0->isNull());
  CPPUNIT_ASSERT_MESSAGE("arr1el0 is an object (should be string)",!arr1el0->isObject());
  */
  IDocumentNode* arr1el1 = arr1->at(1);
  LOG(DEBUG) << "Checking arr1el1";
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is invalid",strcmp(arr1el1->asString().c_str(),"av2") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is not a string (should be string)",arr1el1->isString());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is an array (should be string)",!arr1el1->isArray());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is a boolean (should be string)",!arr1el1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is a double (should be string)",!arr1el1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is an integer (should be string)",!arr1el1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is a null (should be string)",!arr1el1->isNull());
  CPPUNIT_ASSERT_MESSAGE("arr1el1 is an object (should be string)",!arr1el1->isObject());
  */
  IDocumentNode* obj1 = root->at("obj1");
  LOG(DEBUG) << "Checking obj1";
  CPPUNIT_ASSERT_MESSAGE("obj1 is not a object (should be object)",obj1->isObject());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a double (should be object)",!obj1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a boolean (should be object)",!obj1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("obj1 is an integer (should be object)",!obj1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a string (should be object)",!obj1->isString());
  CPPUNIT_ASSERT_MESSAGE("obj1 is a null (should be object)",!obj1->isNull());
  CPPUNIT_ASSERT_MESSAGE("obj1 is an array (should be object)",!obj1->isArray());
  IDocumentNode* obj1subel1 = obj1->at("subel1");
  LOG(DEBUG) << "Checking obj1subel1";
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is invalid",strcmp(obj1subel1->asString().c_str(),"subval1") == 0);
  /*
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is not a string (should be string)",obj1subel1->isString());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is an array (should be string)",!obj1subel1->isArray());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is a boolean (should be string)",!obj1subel1->isBoolean());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is a double (should be string)",!obj1subel1->isDouble());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is an integer (should be string)",!obj1subel1->isInteger());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is a null (should be string)",!obj1subel1->isNull());
  CPPUNIT_ASSERT_MESSAGE("obj1subel1 is an object (should be string)",!obj1subel1->isObject());
  */
  } catch (std::exception& e) {
    LOG(DEBUG) << "EXCEPTION IN TEST RESULT N: " << e.what();
    throw e;
  }
}


