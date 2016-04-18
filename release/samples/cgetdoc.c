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

    CResponse* response = connection_getDocument(ml,"/some/doc.json");

    const int rt = response_GetResponseType(response);
    printf("Response type: %i \n",rt);
    const int rc = response_GetResponseCode(response);
    printf("Response code: %i \n",rc);
    if (RESPONSETYPE_JSON == rt) {
    	printf("This is /some/doc.json: %s \n",response_Json(response) );
    	// TODO convert to struct and output relevant fields
    } else {
    	printf("Response: %s \n",response_String(response));
    }

    printf("cgetdoc complete\n");
    return 0;
}
