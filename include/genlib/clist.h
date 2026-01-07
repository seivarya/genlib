/* clist.h: circular linked list header file */

#ifndef CLIST_H
#define CLIST_H

#include "../../src/list/clist/cnode/cnode.h"

typedef struct clist {
	cnode *head;
	cnode *tail;
	size_t length;
} clist;

clist* clist_construct(void);
void clist_destruct(clist *list);

void clist_insert(clist *list, size_t index, void *data, size_t size);
void clist_remove(clist *list, size_t index);
void clist_reverse(clist *list);

void* clist_fetch_data(clist *list, size_t index);

#endif /* clist_h */
