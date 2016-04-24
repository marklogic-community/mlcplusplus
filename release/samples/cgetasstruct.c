/*
 * A C language sample to show fetching a document as a C struct and printing out to screen
 */
#include <stdio.h>
#include "ConnectionWrapper.h"
#include "ConnectionFactoryWrapper.h"
#include "ResponseWrapper.h"
#include "CStruct.h"
#include "CStructWrapper.h"

int main(int argc, const char * argv[])
{
  printf("Running getasstruct...\n");

  CConnection* ml = ml_samples_connectionfactory_getConnection();

  char* uri = "/some/doc.json";
  if (argc > 1) {
    uri = argv[1];
  }
  CResponse* response = ml_connection_getDocument(ml,uri);

  const int rt = ml_response_GetResponseType(response);
  printf("Response type: %i \n",rt);
  const int rc = ml_response_GetResponseCode(response);
  printf("Response code: %i \n",rc);
  if (RESPONSETYPE_JSON == rt || RESPONSETYPE_XML == rt) {
    //printf("This is /some/doc.json: %s \n",response_Json(response) );
    // convert to struct and output relevant fields
    struct ml_samples_sampledoc result; // from CStruct.h
    ml_samples_cstruct_unpack(response,&result); // from CStructWrapper.h
    printf("%s contains a sampledoc struct with 'first' set to '%s' and 'second' set to '%s' \n",uri,result.first,result.second);
  } else {
    printf("Response: %s : %s \n",uri,ml_response_String(response));
  }

  printf("getasstruct complete\n");
  return 0;
}
