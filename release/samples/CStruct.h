
/*
 * A C struct for the sample JSON doc: {"first":"something","second":"another thing"}
 *
 * In a real application this file would be replaced by your existing C struct declaration files.
 * This is why I've chosen to define this struct in its own file, and not include CStructWrapper.h.
 * Thus in your own application you only need to provide code like that in CStructWrapper.h/cpp and NOT
 * any of the code in this file.
 */
#ifndef CSTRUCT_H
#define CSTRUCT_H

struct sampledoc {
	char* first;
	char* second;
};

#endif
