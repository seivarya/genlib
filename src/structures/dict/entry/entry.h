#ifndef ENTRY_H
#define ENTRY_H

#include <stdlib.h>
#include <genlib/td.h>


typedef struct entry entry;

struct entry {
	int key;
	const td *type;
	void *data; // works as <value> in <key: value>
};


#endif
