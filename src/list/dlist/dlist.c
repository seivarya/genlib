/* dlist.c: doubly linked list methods */

#include <stdlib.h>
#include <stdio.h>

#include "dnode.h" 
#include "../../../include/genlib/dlist.h"

/* info: private methods */

static inline int _validate_dlist(dlist *list) {
	if (list == NULL) {
		fprintf(stderr, "=== error: _validate_dlist(): list doesn't exist or it has been destroyed ===\n");
		return 0;
	}
	return 1;
}

static inline int _validate_dindex(dlist *list, size_t index) {
	if (!list || index >= list->length) {
		fprintf(stderr, "=== error: _validate_dindex(): index [%zu] out of bounds <length: %zu> ===\n", index, list->length);
		return 0;
	}
	return 1;
}

static dnode* _dlist_iterate(dlist *list, size_t index) {
	if (!_validate_dindex(list, index))
		return NULL;

	size_t mid_index = list->length / 2;
	dnode *cursor;

	/* iterate: optimized */
	if (index <= mid_index) {
		cursor = list->head;
		while (index != 0) {
			cursor = cursor->next;
			index--;
		}
	} else {
		cursor = list->tail;
		while (index != 0) {
			cursor = cursor->previous;
			index--;
		}
	}

	return cursor;
}

/* info: public methods */

dlist* dlist_construct(void) {
	dlist *list = malloc(sizeof(dlist));
	if (list) {
		list->head = NULL;
		list->tail = NULL;
		list->length = 0;
		return list;
	}
	fprintf(stderr, "=== error: dlist_construct(): malloc failed ===\n");
	return NULL;
}

void dlist_destruct(dlist *list) {
	if (!_validate_dlist(list))
		return;

	dnode *current = list->head;
	while (current != NULL) {
		dnode *next = current->next;
		dnode_destruct(current);
		current = next;
	}

	free(list);
}

void dlist_insert(dlist *list, size_t index, void *data, size_t size) {
	if (!_validate_dlist(list))
		return;

	if (index > list->length)
		return;

	dnode *new_node = dnode_construct(data, size);
	if (!new_node)
		return;

	/* case 1: insert at head */
	if (index == 0) {
		if (list->length == 0) {
			list->head = list->tail = new_node;
		} else {
			new_node->next = list->head;
			new_node->previous = NULL;
			list->head->previous = new_node;
			list->head = new_node;
		}
	}

	/* case 2: insert at tail */
	else if (index == list->length) {
		new_node->previous = list->tail;
		list->tail->next = new_node;
		list->tail = new_node; /* new_node->next: NULL: default */
	}

	/* case 3: insert in the middle */
	else {
		dnode *on_index_node = _dlist_iterate(list, index);
		new_node->previous = on_index_node->previous;
		new_node->next = on_index_node;

		on_index_node->previous->next = new_node;
		on_index_node->previous = new_node;
	}

	list->length++;
}

void dlist_remove(dlist *list, size_t index) {
	if (!_validate_dindex(list, index))
		return;

	dnode *target;

	/* case 1: removing the head */
	if (index == 0) {
		target = list->head;

		if (list->length < 2) {
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->head = target->next;
			list->head->previous = NULL;
		}
	}

	/* case 2: removing the tail */
	else if (index == list->length - 1) {
		target = list->tail;

		list->tail->previous->next = NULL;
		list->tail = list->tail->previous;
	}

	/* case 3: removing from middle */
	else {
		target = _dlist_iterate(list, index);

		target->previous->next = target->next;
		target->next->previous = target->previous;
	}

	dnode_destruct(target);
	list->length--;
}

void* dlist_fetch_data(dlist *list, size_t index) {
	if (!_validate_dindex(list, index)) return NULL;

	dnode *node = _dlist_iterate(list, index);
	return node ? node->data : NULL;
}

void dlist_reverse(dlist *list) {
	if (!_validate_dlist(list) || list->length < 2) return;

	dnode *current = list->head;
	dnode *temp = NULL;
	list->tail = list->head;

	while(current != NULL) {
		temp = current->previous;
		current->previous = current->next;
		current->next = temp;
		current = current->previous;
	} //  WARNING: issue if the length is 2 ??
	if (temp) { 
		list->head = temp->previous ;
	}
} /* dlist_c */
