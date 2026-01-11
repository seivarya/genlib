#include "../include/genlib/genlib.h"
#include <stdio.h>
#include <stdlib.h>
// dlist* dlist_construct(void);
// void dlist_destruct(dlist *list);
//
// void dlist_insert(dlist *list, size_t index, void *data, size_t size);
// void dlist_remove(dlist *list, size_t index);
// void dlist_reverse(dlist *list);
//
// void* dlist_fetch_data(dlist *list, size_t index);

int main(void) {
	dlist *list = dlist_construct();
	int var = 32;
	dlist_insert(list, 0, &var, sizeof(var));
	printf("%d\n", *(int*)dlist_fetch_data(list, 0));
	dlist_destruct(list);
}
