/* slist.c: singly linked list methods */

#include <stdlib.h>
#include <stdio.h>

#include "snode/snode.h" 
#include "../../../../include/genlib/slist.h"

/* info: private methods */

static inline int _validate_slist(slist *list) {
	if (list == NULL) {
		fprintf(stderr, "=== error: _validate_slist(): list doesn't exist or it has been destroyed ===\n");
		return 0;
	}
	return 1;
}

static inline int _validate_sindex(slist *list, size_t index) {
	if (!list || index >= list->length) {
		fprintf(stderr, "=== error: _validate_sindex(): index [%zu] out of bounds <length: %zu> ===\n", index, list->length);
		return 0;
	}
	return 1;
}

static snode* _slist_iterate(slist *list, size_t index) {
	if (!_validate_sindex(list, index))
		return NULL;

	snode *cursor = list->head;
	for (size_t i = 0; i < index; i++)
		cursor = cursor->next;

	return cursor;
}

/* info: public methods */

slist* slist_construct(void) {
	slist *list = malloc(sizeof(slist));
	if (list) {
		list->head = NULL;
		list->length = 0;
		return list;
	}
	fprintf(stderr, "=== error: slist_construct(): malloc failed ===\n");
	return NULL;
}

void slist_destruct(slist *list) {
	if (!_validate_slist(list))
		return;

	/* destroy all nodes */
	snode *current = list->head;
	while (current != NULL) {
		snode *next = current->next;
		snode_destruct(current);
		current = next;
	}

	free(list);
}

void slist_insert(slist *list, size_t index, void *data, size_t size) {
	if (!_validate_slist(list))
		return;

	if (index > list->length)
		return;

	snode *new_node = snode_construct(data, size);

	/* insert at head */
	if (index == 0) {
		new_node->next = list->head;
		list->head = new_node;
	}

	/* insert at middle / end */
	else {
		snode *previous = _slist_iterate(list, index - 1);
		new_node->next = previous->next;
		previous->next = new_node;
	}

	list->length++;
}

void slist_remove(slist *list, size_t index) {
	if (!_validate_sindex(list, index))
		return;

	snode *target;

	/* remove head */
	if (index == 0) {
		target = list->head;
		list->head = (list->length < 2) ? NULL : target->next;
	}

	/* remove middle/end */
	else {
		snode *previous = _slist_iterate(list, index - 1);
		target = previous->next;
		previous->next = target->next;
	}

	snode_destruct(target);
	list->length--;
}

void* slist_fetch_data(slist *list, size_t index) {
	if (!_validate_sindex(list, index))
		return NULL;

	snode *node = _slist_iterate(list, index);
	return node ? node->data : NULL;
}

void slist_reverse(slist *list) {
	if (!_validate_slist(list) || list->length < 2)
		return;

	/* iterative reverse */
	snode *previous = NULL;
	snode *current = list->head;
	snode *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	list->head = previous;
} /* slist_c */
