/* slist.h: singly linked list header file */

#ifndef SLIST_H
#define SLIST_H

#include "../../src/list/slist/snode/snode.h"

typedef struct slist {
	snode *head;
	size_t length;
} slist;

slist* slist_construct(void);
void slist_destruct(slist *slist);

void slist_insert(slist *self, size_t index, void *data, size_t size);
void slist_remove(slist *self, size_t index);
void slist_reverse(slist *self);

void* slist_fetch_data(slist *self, size_t index);

#endif /* slist_h */
