/*
 * SearchResultSetTest.cpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#include "SearchResultSetTest.hpp"
#include "SearchResult.hpp"
#include "SearchResultSet.hpp"

#include "ext/easylogging++.h"

using namespace mlclient;

CPPUNIT_TEST_SUITE_REGISTRATION(SearchResultSetTest);

void SearchResultSetTest::setUp(void) {
  LOG(DEBUG) << "ENTERING TEST SUITE SearchResultSetTest";
  // set up connection
  ml = ConnectionFactory::getConnection();
}

void SearchResultSetTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE SearchResultSetTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void SearchResultSetTest::testEmptySearch() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " Entering SearchResultSetTest::testEmptySearch";
  SearchDescription desc; // default empty search object
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  tdcOptions->setContent("\"options\": {\"transform-results\": {\"apply\": \"raw\"}}");
  desc.setOptions(*tdcOptions);
  LOG(DEBUG) << "  Got a blank SearchDescription object instance";

  SearchResultSet* results = new SearchResultSet(ml,desc);

  bool res = results->fetch();
  if (!res) {
    LOG(DEBUG) << "Exception report from fetch() attempt:-";
    LOG(DEBUG) << results->getFetchException()->what();
  }
  std::string blankString("");
  CPPUNIT_ASSERT_MESSAGE("Fetch operation did not succeed", res);

  // get results iterator
  for (auto& iter : *results) {
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter.getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",0!=blankString.compare(iter.getDetailContent()));
  }

  // NB Response deleted by SearchResultSet fetch() method
}
