/*
 * A C language sample to show fetching a document - functionally equivalent to the C++ getdoc.cpp sample app.
 */
#include <stdio.h>
#include "ConnectionWrapper.h"
#include "ConnectionFactoryWrapper.h"
#include "ResponseWrapper.h"

int main(int argc, const char * argv[])
{
	printf("Running cgetdoc...\n");

    CConnection* ml = connectionfactory_getConnection();

    char* uri = "/some/doc.json";
    if (argc > 1) {
    	uri = argv[1];
    }
    CResponse* response = connection_getDocument(ml,uri);

    const int rt = response_GetResponseType(response);
    printf("Response type: %i \n",rt);
    const int rc = response_GetResponseCode(response);
    printf("Response code: %i \n",rc);
    if (RESPONSETYPE_JSON == rt) {
    	//int length = response_length(response);
    	//char buffer[length + 1];
    	//response_Json(response,buffer);
    	//printf("This is %s: %s \n",uri,buffer );
    	printf("This is JSON doc %s: %s \n",uri,response_String(response));
    } else if (RESPONSETYPE_XML == rt) {
    	//const char* xml = response_Xml(response);
    	printf("This is XML doc %s: %s",uri,response_String(response));
    } else {
    	printf("This is String doc %s: %s \n",uri,response_String(response));
    }

    printf("cgetdoc complete\n");
    return 0;
}
