#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/genlib/td.h"

int td_validator(const td *t) {
	if (t && t->magic == TD_MAGIC) {
		return 1;
	}
	perror("=== TD_MAGIC: failed === \n"); // TODO: maybe work on *good* error messages later
	return 0;
}

void print_uint(void *data) {
	printf("%u\n", *(unsigned int *)data);
}

void print_long(void *data) {
	printf("%ld\n", *(long *)data);
}

void print_ulong(void *data) {
	printf("%lu\n", *(unsigned long *)data);
}

void print_short(void *data) {
	printf("%hd\n", *(short *)data);
}

void print_ushort(void *data) {
	printf("%hu\n", *(unsigned short *)data);
}

void print_bool(void *data) {
	printf("%s\n", (*(int*)data) ? "true" : "false");
}

void print_size_t(void *data) {
	printf("%zu\n", *(size_t *)data);
}

void print_str(void *data) {
	printf("%s\n", (char *)data);
}

void print_char(void *data) {
	printf("%c\n", *(char *)data);
}
void print_int(void *data) {
	printf("%d\n", *(int *)data);
}
// size_t (*hash)(void *key); 
// int (*compare)(void *a, void *b); 
// void * (*copy)(void *data); 
// void (*destruct)(void *data); // user's custom destructor for objects

size_t hash_int(void *data) {
	return (size_t)(*(const int*)data); // test
}

size_t hash_str(void *data) {
	unsigned int hash = 0;
	char *str = (char *)data;
	int c;

	while ((c = *str++)) {
		hash += c;
	}
	return hash; // test; it's a very verys shit hash function for actual use case
}

int compare_int(void *a, void *b) {
	int i1 = *(int *)a;
	int i2 = *(int *)b;

	return i1 - i2; // basic only for now

}

int compare_str(void *a, void *b) {
	char * s1 = (char *)a;
	char * s2 = (char *)b;
	int diff = strcmp(s1, s2);
	return diff;
}

void destruct_int(void *data) { // user's custom destructor for objects
	if (data) {
		free(data);
	}
}

void destruct_str(void *data) { // user's custom destructor for objects
	if (data) {
		free(data);
	}
}

// int (*compare)(void *a, void *b); 
// 	void * (*copy)(void *data); 
// 	void (*destruct)(void *data); // user's custom destructor for objects

const td TD_STR = {
	.magic = TD_MAGIC,
	.size  = sizeof(char *),
	.print = print_str,
	.hash = hash_str,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL

};

const td TD_INT = {
	.magic = TD_MAGIC,
	.size = sizeof(int),
	.print = print_int,
};

const td TD_UINT = {
	.magic = TD_MAGIC,
	.size = sizeof(unsigned int),
	.print = print_uint,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};

const td TD_LONG = {
	.magic = TD_MAGIC,
	.size = sizeof(long),
	.print = print_long,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};

const td TD_ULONG = {
	.magic = TD_MAGIC,
	.size = sizeof(unsigned long),
	.print = print_ulong,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};

const td TD_SHORT = {
	.magic = TD_MAGIC,
	.size = sizeof(short),
	.print = print_short,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};

const td TD_USHORT = {
	.magic = TD_MAGIC,
	.size = sizeof(unsigned short),
	.print = print_ushort,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};

const td TD_BOOL = {
	.magic = TD_MAGIC,
	.size = sizeof(int),    // C has no true bool in stdlib unless <stdbool.h>
	.print = print_bool,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};

const td TD_SIZE_T = {
	.magic = TD_MAGIC,
	.size = sizeof(size_t),
	.print = print_size_t,
	.hash = NULL,
	.compare = NULL,
	.copy = NULL,
	.destruct = NULL
};


const td TD_CHAR = {
	.magic = TD_MAGIC,
	.size  = sizeof(char),
	.print = print_char
};

// size_t hash_uint(void *data) {
// }
// size_t hash_long(void *data) {
//
// }
//
// size_t hash_ulong(void *data) {
//
// }
//
// size_t hash_short(void *data) {
//
// }
//
// size_t hash_ushort(void *data) {
//
// }
//
// size_t hash_bool(void *data) {
//
// }
//
// size_t hash_size_t(void *data) {
//
// }

