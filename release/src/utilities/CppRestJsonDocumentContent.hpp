/*
 * CppRestJsonDocumentContent.hpp
 *
 * \date 2016-05-01
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \brief Provides a convenience Json DocumentContent wrapper for use with Microsoft's CPP REST API
 */

#ifndef SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_
#define SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_

#include "../DocumentContent.hpp"

namespace mlclient {

namespace utilities {

/**
 * \class CppRestJsonDocumentContent
 * \author Adam Fowler <adam.fowler@marklogic.com>
 * \since 8.0.0
 * \date 2016-05-10
 *
 * \brief A TextDocumentContent instance that wraps a Microsoft cpprest JSON value object.
 *
 * Used by the CppRestJsonHelper class
 *
 * \note This class has an external dependency on Microsoft's C++ cpprest API. As this API is required to use MarkLogic's C++ wrapper (this API)
 * , this does not introduce any extra dependencies.
 */
class CppRestJsonDocumentContent : public TextDocumentContent {
public:
  /**
   * \brief Default constructor
   */
  CppRestJsonDocumentContent();
  /**
   * \brief Virtual destructor to allow subclassing
   */
  virtual ~CppRestJsonDocumentContent();

  /// \name cpprestjsondocumentcontent_overrides Overridden functions from base class
  /// @{
  /**
   * \brief Sets the content of this document instance from a Microsoft cpprest API web::json::value instance.
   *
   * \param json The cpprest API web::json::value instance to copy
   */
  void setContent(const web::json::value& json);

  /**
   * \brief Returns an ostream instance for the underlying content.
   *
   * \note Actually returns a std::ostringstream instance that is newly created by this function. Assumes the caller destroys the stream once done.
   *
   * \return A std::ostream instance pointer. Assumes the caller deletes the pointer once done.
   */
  std::ostream* getStream();
  /// @}

  /// \name cpprestjsondocumentcontent_functions These functions are new to this subclass.
  /// @{
  /**
   * \brief Returns the underlying Microsoft cpprest API web::json::value object.
   *
   * \return The underlying Microsoft cpprest web::json::value object.
   */
  web::json::value& getJson();
  /// @}

private:
  class Impl; // forward declaration
  Impl* mImpl;

};

} // end utilities namespace

} // end mlclient namespace


#endif /* SRC_UTILITIES_CPPRESTJSONDOCUMENTCONTENT_HPP_ */
