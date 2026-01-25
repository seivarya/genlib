/* dlist.h: doubly linked list header file */

#ifndef DLIST_H
#define DLIST_H

#include "../../src/structures/list/dlist/dnode/dnode.h"

typedef struct dlist {
	dnode *head;
	dnode *tail;
	size_t length;
} dlist;

dlist* dlist_construct(void);
void dlist_destruct(dlist *list);

void dlist_insert(dlist *list, size_t index, void *data, const td *type);
void dlist_remove(dlist *list, size_t index);
void dlist_reverse(dlist *list);

void* dlist_fetch_data(dlist *list, size_t index);

#endif /* dlist_h */
