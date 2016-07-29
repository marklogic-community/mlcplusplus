/*
 * SearchResultSetTest.cpp
 *
 *  Created on: 26 May 2016
 *      Author: adamfowler
 */

#include "SearchResultSetTest.hpp"
#include "mlclient/SearchResult.hpp"
#include "mlclient/SearchResultSet.hpp"

#include "mlclient/logging.hpp"

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
  SearchDescription* desc = new SearchDescription; // default empty search object
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  tdcOptions->setContent("{\"transform-results\": {\"apply\": \"raw\"}}");
  desc->setOptions(*tdcOptions);
  GenericTextDocumentContent* tdcBlankSearch = new GenericTextDocumentContent;
  tdcBlankSearch->setContent("{\"collection-query\": {\"uri\": [\"SomeNonExistentCollection\"]}}"); // TODO wrap with {} rather than using internals
  desc->setQuery(*tdcBlankSearch);
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
  int count = 0;
  for (SearchResultSetIterator* iter = results->begin();*iter != *(results->end());++(*iter)) {
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter->first().getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",nullptr != iter->first().getDetailContent());
    ++count;
    if (count > 30) break;
  }

  // NB Response deleted by SearchResultSet fetch() method
}

void SearchResultSetTest::testThreePages() {
  TIMED_FUNC(testEmptySearch);
  LOG(DEBUG) << " --------------------------------------------";
  LOG(DEBUG) << " Entering SearchResultSetTest::testThreePages";
  const IDocumentContent* finalDocContent;
  { // start destruction block
  SearchDescription* desc = new SearchDescription; // default empty search object
  GenericTextDocumentContent* tdcOptions = new GenericTextDocumentContent;
  tdcOptions->setContent("{\"transform-results\": {\"apply\": \"raw\"}}"); // TODO force page size to 10 (server may be different)
  tdcOptions->setMimeType(IDocumentContent::MIME_JSON);
  desc->setOptions(*tdcOptions);
  GenericTextDocumentContent* tdcBlankSearch = new GenericTextDocumentContent;
  tdcBlankSearch->setContent("{\"collection-query\": {\"uri\": [\"zoo\"]}}"); // TODO wrap with {} rather than using internals
  tdcBlankSearch->setMimeType(IDocumentContent::MIME_JSON);
  //LOG(DEBUG) << "SearchResultSetTest search content: " << tdcBlankSearch->getContent();
  desc->setQuery(*tdcBlankSearch);
  LOG(DEBUG) << "  Got a three pages SearchDescription object instance";

  SearchResultSet* results = new SearchResultSet(ml,desc);
  results->setMaxResults(500);

  bool res = results->fetch(); // BLOCKS
  if (!res) {
    LOG(DEBUG) << "Exception report from fetch() attempt:-";
    LOG(DEBUG) << results->getFetchException()->what();
    throw results->getFetchException();
  }
  std::string blankString("");
  CPPUNIT_ASSERT_MESSAGE("Fetch operation did not succeed", res);

  // TODO validate that total result count is greater than 20 (and thus falls across 3 pages) - should be 23

  // get results iterator
  int count = 0;
  //for (auto& iter : *results) {
  LOG(DEBUG) << "result set total: " << results->getTotal();
  SearchResultSetIterator* iter = results->begin();
  SearchResultSetIterator* end = results->end();
  for (;(*iter) != (*end);++(*iter)) {
    LOG(DEBUG) << " Result " << count << " (0 based):-";
    LOG(DEBUG) << "  URI: " << iter->first().getUri();
    LOG(DEBUG) << "  Content: " << iter->first().getDetailContent()->getContent();
    if (0 == count) {
      finalDocContent = iter->first().getDetailContent();
    }
    CPPUNIT_ASSERT_MESSAGE("Result does not have a URI",0!=blankString.compare(iter->first().getUri()));
    CPPUNIT_ASSERT_MESSAGE("Result does not have content",nullptr != iter->first().getDetailContent());
    ++count;
    //if (count > 30) break;
  }
  LOG(DEBUG) << "Completed iterator loop. Deleting results.";

  delete results;

  } // end destruction block

  // TODO add above to its own section, and test a std:move'd part of one of the result's getDetailContent() outputs, and check it's valid

  LOG(DEBUG) << " First result document content value: " << finalDocContent->getContent();
  CPPUNIT_ASSERT_MESSAGE(" First Result has not leaked (not nullptr)",nullptr != finalDocContent);

  // NB Response deleted by SearchResultSet fetch() method
}
