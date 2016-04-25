
#include "ResponseUtilities.hpp"
#include "../Response.hpp"
#include "../ResponseCodes.hpp"
#include "InvalidFormatException.hpp"

namespace mlclient {

namespace utilities {
  using namespace mlclient;

/*
 * Tries to return the response as an XML.  Throws ResponseTypeException if it's
 * not XML.
 */
/*
xmlDocPtr Response::Xml() const {
    return nullptr;
}*/

const pugi::xml_document& ResponseUtilities::asXml(const Response& resp) {
  //static const pugi::xml_document& doc = _xml;
  //return doc;
  // TODO sanity check/warning for type of response
  if (resp.getResponseType() == ResponseType::XML) {
    // get response raw text
    //const std::string asstr = *_content.get();
    //const std::string asstr = _content;
    //std::cout << "Content: " << asstr << std::endl;
    // parse in to XML object
    // set response XML
    static pugi::xml_document doc;
    static const pugi::xml_document& docref = doc;
    pugi::xml_parse_result result = doc.load_string(resp.getContent().c_str());

    if (result)
    {
      //std::cout << "XML [" << asstr << "] parsed without errors]\n\n"; // , attr value: [" << doc.child("node").attribute("attr").value()
      return docref;
    }
    else
    {
      std::cout << "XML [" << resp.getContent() << "] parsed with errors]\n";
      std::cout << "Error description: " << result.description() << "\n";
      std::cout << "Error offset: " << result.offset << " (error at [..." << resp.getContent() << "]\n\n";
      // TODO throw something here
      throw InvalidFormatException();
    }
  } else {
    throw InvalidFormatException();
  }
}
/*
void Response::SetXml(const pugi::xml_document& doc) {
  _xml = doc;
}*/


/*
 * Guess what this does.
 */
const web::json::value ResponseUtilities::asJson(const Response& resp) {
}
/*
void Response::SetJson(const web::json::value& json) {
  _json = json;
}*/


}
}
