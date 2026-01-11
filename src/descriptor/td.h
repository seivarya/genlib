#ifndef TD_H
#define TD_H

#include <stdlib.h>

typedef struct td td;

struct td {
	char* name;
	size_t size;
	void (*print)(void*);
};

td* td_construct(char *name);
void td_destruct(td *td);

#endif
