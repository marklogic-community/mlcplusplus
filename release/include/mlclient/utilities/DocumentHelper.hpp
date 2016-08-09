/*
 * DocumentHelper.hpp
 *
 *  Created on: 9 Aug 2016
 *      Author: adamfowler
 */

#ifndef INCLUDE_MLCLIENT_UTILITIES_DOCUMENTHELPER_HPP_
#define INCLUDE_MLCLIENT_UTILITIES_DOCUMENTHELPER_HPP_

#include <mlclient/Document.hpp>
#include <mlclient/Response.hpp>
#include <mlclient/DocumentContent.hpp>

namespace mlclient {

namespace utilities {

class DocumentHelper {
public:
  /**
   * \brief A very, very simple function to take the content from a response and wrap in a Document object
   *
   * \note You should normally use contentFromResponse(resp) only. This function ONLY returns the content wrapped as a document
   * for convenience. More sophisticated methods in the Connection class handle all fields and multi-part responses.
   *
   * \throw InvalidFormatException if the Response does not have a mime type of application/xml or application/json or plain/text, or if a parsing error occurs.
   *
   * \param resp The MarkLogic C++ API Response object instance.
   * \return An IDocumentContent* instance created from the Response.
   */
  static Document* fromResponse(const Response& resp);

  /**
   * \brief A very, very simple function to take the content from a response and wrap in a Document object
   *
   * \note You should normally use contentFromResponse(resp) only. This function ONLY returns the content wrapped as a document
   * for convenience. More sophisticated methods in the Connection class handle all fields and multi-part responses.
   *
   * \throw InvalidFormatException if the Response does not have a mime type of application/xml or application/json or plain/text, or if a parsing error occurs.
   *
   * \param resp The MarkLogic C++ API Response object instance.
   * \param doc An IDocumentContent instance to populate from the Response.
   */
  static void fromResponse(const Response& resp,Document& doc);

  /**
   * \brief Returns an IDocumentContent* instance from a response. Retrieves content only, and only for a single document.
   *
   * \throw InvalidFormatException if the Response does not have a mime type of application/xml or application/json or plain/text, or if a parsing error occurs.
   *
   * \param resp The MarkLogic C++ API Response object instance.
   * \return An IDocumentContent* instance created from the Response.
   */
  static IDocumentContent* contentFromResponse(const Response& resp);
};

} // end namespace utilities
} // end namespace mlclient



#endif /* INCLUDE_MLCLIENT_UTILITIES_DOCUMENTHELPER_HPP_ */
