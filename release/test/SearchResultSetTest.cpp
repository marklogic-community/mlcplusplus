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

  // TODO put 23 documents in to the test DB, in the ThreePagesCollection collection
  /*
  std::string jsonString = "{\"some\": \"doc\"}";
  GenericTextDocumentContent* tdcDoc = new GenericTextDocumentContent;
  tdcDoc->setContent(jsonString);
  tdcDoc->setMimeType(IDocumentContent::MIME_JSON);
  ml->save
  NEED THE DOCUMENT INERFACE SO I CAN SET COLLECTION
  */
}

void SearchResultSetTest::tearDown(void) {
  LOG(DEBUG) << "LEAVING TEST SUITE SearchResultSetTest";
  // delete all content
  ConnectionFactory::releaseConnection(ml);
  ml = NULL;
}

void SearchResultSetTest::testEmptySearch() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering SearchResultSetTest::testEmptySearch";
  SearchDescription desc; // default empty search object
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  tdcOptions->setContent("\"options\": {\"transform-results\": {\"apply\": \"raw\"}}");
  desc.setOptions(*tdcOptions);
  GenericTextDocumentContent* tdcBlankSearch = new GenericTextDocumentContent;
  tdcBlankSearch->setContent("\"query\": {\"collection-query\": {\"collection\": [\"SomeNonExistentCollection\"]}}"); // TODO wrap with {} rather than using internals
  desc.setQuery(*tdcBlankSearch);
  LOG(DEBUG) << "  Got a blank SearchDescription object instance";

  SearchResultSet* results = new SearchResultSet(ml,desc);

  bool res = results->fetch();
  if (!res) {
    LOG(DEBUG) << "Exception report from fetch() attempt:-";
    LOG(DEBUG) << results->getFetchException()->what();
  }
  std::string blankString("");
  CPPUNIT_ASSERT_MESSAGE("Fetch operation did not succeed", res);

  // TODO validate result set size is zero, error if not (it likely means the search definition was not processed/passed correctly)

  // get results iterator
  for (auto& iter : *results) {
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter.getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",0!=blankString.compare(iter.getDetailContent()));
  }

  // NB Response deleted by SearchResultSet fetch() method
}

void SearchResultSetTest::testThreePages() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering SearchResultSetTest::testThreePages";
  SearchDescription desc; // default empty search object
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  tdcOptions->setContent("\"options\": {\"transform-results\": {\"apply\": \"raw\"}}"); // TODO force page size to 10 (server may be different)
  desc.setOptions(*tdcOptions);
  GenericTextDocumentContent* tdcBlankSearch = new GenericTextDocumentContent;
  tdcBlankSearch->setContent("\"query\": {\"collection-query\": {\"collection\": [\"ThreePagesCollection\"]}}"); // TODO wrap with {} rather than using internals
  desc.setQuery(*tdcBlankSearch);
  LOG(DEBUG) << "  Got a three pages SearchDescription object instance";

  SearchResultSet* results = new SearchResultSet(ml,desc);

  bool res = results->fetch();
  if (!res) {
    LOG(DEBUG) << "Exception report from fetch() attempt:-";
    LOG(DEBUG) << results->getFetchException()->what();
  }
  std::string blankString("");
  CPPUNIT_ASSERT_MESSAGE("Fetch operation did not succeed", res);

  // TODO validate that total result count is greater than 20 (and thus falls across 3 pages) - should be 23

  // get results iterator
  int count = 0;
  for (auto& iter : *results) {
    LOG(DEBUG) << " Result " << count << ":-";
    LOG(DEBUG) << "  URI: " << iter.getUri();
    LOG(DEBUG) << "  Content: " << iter.getDetailContent();
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter.getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",0!=blankString.compare(iter.getDetailContent()));
  }

  // NB Response deleted by SearchResultSet fetch() method
}
