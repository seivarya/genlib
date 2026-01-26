#ifndef TD_H
#define TD_H

#define TD_MAGIC 0x6969

#include <stddef.h>
#include <stdint.h>

typedef struct td td;

struct td {
	uint32_t magic;
	size_t size;
	void (*print)(void *); 
	size_t (*hash)(void *key);
	int (*compare)(void *a, void *b); 
	void (*destruct)(void *data); // user's custom destructor for objects
	void * (*copy)(void *data); 

};

int td_validator(const td *t);

extern const td TD_INT;
extern const td TD_STR;
extern const td TD_UINT;
extern const td TD_LONG;
extern const td TD_ULONG;
extern const td TD_SHORT;
extern const td TD_USHORT;
extern const td TD_BOOL;
extern const td TD_SIZE_T;
extern const td TD_CHAR;

#endif
