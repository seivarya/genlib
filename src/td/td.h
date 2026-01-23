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
	void * (*copy)(void *data); 
	void (*destruct)(void *data); // user's custom destructor for objects

};

int td_validator(const td *t);

#endif
