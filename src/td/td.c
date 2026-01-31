#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rvlib/td.h"

int td_validator(const td *t) {
	if (t == NULL) {
		fprintf(stderr, "Error: %s: NULL type descriptor provided for validation.\n", __func__);
		return 0;
	}
	if (t->magic != TD_MAGIC) {
		fprintf(stderr, "Error: %s: Type descriptor magic number mismatch. Expected 0x%X, got 0x%X.\n",
				__func__, TD_MAGIC, t->magic);
		return 0;
	}
	return 1;
}
// print
void print_uint(void *data);
void print_long(void *data);
void print_ulong(void *data);
void print_short(void *data);
void print_ushort(void *data);
void print_bool(void *data);
void print_size_t(void *data);
void print_str(void *data);
void print_char(void *data);
void print_int(void *data);

// hash
size_t hash_int(void *data);
size_t hash_str(void *data);
size_t hash_uint(void *data);
size_t hash_long(void *data);
size_t hash_ulong(void *data);
size_t hash_short(void *data);
size_t hash_ushort(void *data);
size_t hash_bool(void *data);
size_t hash_size_t(void *data);
size_t hash_char(void *data);

// compare
int compare_int(void *a, void *b);
int compare_str(void *a, void *b);
int compare_uint(void *a, void *b);
int compare_long(void *a, void *b);
int compare_ulong(void *a, void *b);
int compare_short(void *a, void *b);
int compare_ushort(void *a, void *b);
int compare_bool(void *a, void *b);
int compare_size_t(void *a, void *b);
int compare_char(void *a, void *b);

// destruct
void destruct_int(void *data);
void destruct_str(void *data);
void destruct_uint(void *data);
void destruct_long(void *data);
void destruct_ulong(void *data);
void destruct_short(void *data);
void destruct_ushort(void *data);
void destruct_bool(void *data);
void destruct_size_t(void *data);
void destruct_char(void *data);

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
	// unsigned int hash = 0;
	char *str = (char *)data;
	printf("%s\n", str);
	// char *str = (char *)data;
	// int c;
	//
	// while ((c = *str++)) {
	// 	hash += c;
	// }
	return 3; // test; it's a very verys shit hash function for actual use case
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

