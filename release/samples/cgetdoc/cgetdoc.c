//
// Copyright (c) MarkLogic Corporation. All rights reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// A C language sample to show fetching a document - functionally equivalent to the C++ getdoc.cpp sample app.
//
#include <stdio.h>
#include <mlclient/ConnectionWrapper.h>
#include "ccommon/ConnectionFactoryWrapper.h"
#include <mlclient/ResponseWrapper.h>

int main(int argc, const char * argv[])
{
	printf("Running cgetdoc...\n");

	CConnection* ml = ml_samples_connectionfactory_getConnection();

	const char* uri = "/some/doc.json";
	if (argc > 1) {
		uri = argv[1];
	}
	CResponse* response = ml_connection_getDocument(ml,uri);

	const int rt = ml_response_GetResponseType(response);
	printf("Response type: %i \n",rt);
	const int rc = ml_response_GetResponseCode(response);
	printf("Response code: %i \n",rc);
	if (RESPONSETYPE_JSON == rt) {
		//int length = response_length(response);
		//char buffer[length + 1];
		//response_Json(response,buffer);
		//printf("This is %s: %s \n",uri,buffer );
		printf("This is JSON doc %s: %s \n",uri,ml_response_String(response));
	} else if (RESPONSETYPE_XML == rt) {
		//const char* xml = response_Xml(response);
		printf("This is XML doc %s: %s",uri,ml_response_String(response));
	} else {
		printf("This is String doc %s: %s \n",uri,ml_response_String(response));
	}

	printf("cgetdoc complete\n");
	return 0;
}
