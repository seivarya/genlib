/* clist.c: circualr linked list methods */

#include <stdlib.h>
#include <stdio.h>

#include "cnode/cnode.h" 
#include "../../../../include/genlib/clist.h"

/* info: private methods */

static inline int _validate_clist(clist *list) {
	if (list == NULL) {
		fprintf(stderr, "=== error: list doesn't exist or it has been destroyed ===\n");
		return 0;
	}
	return 1;
}

static inline int _validate_dindex(clist *list, size_t index) {
	if (!list || index >= list->length) {
		fprintf(stderr, "=== error: index [%zu] out of bounds <length: %zu> ===\n", index, list->length);
		return 0;
	}
	return 1;
}

static cnode* _clist_iterate(clist *list, size_t index) {
	if (!_validate_dindex(list, index)) 
		return NULL;

	size_t mid_index = (list->length / 2);
	cnode *cursor;

	/* iterate */
	if (index <= mid_index) {
		cursor = list->head;
		while(index != 0) {
			cursor = cursor->next;
			index--;
		}
	} else {
		cursor = list->tail;
		size_t steps = list->length - index - 1; // index conversion
		while(steps != 0) {
			cursor = cursor->previous;
			steps--;
		}
	}

	return cursor;
}

clist* clist_construct(void) {
	clist* list = malloc(sizeof(clist));
	if (list) {
		list->head = NULL;	
		list->tail = NULL;
		list->length = 0;
		return list;
	}
	fprintf(stderr, "=== error: clist_construct(): malloc failed ===\n");
	return NULL;
}

void clist_destruct(clist *list) {
	if (!_validate_clist(list)) 
		return;

	cnode *current = list->head;
	while (current != NULL) {
		cnode *next = current->next;
		cnode_destruct(current);
		current = next;
	}
	free(list);
}

void clist_insert(clist *list, size_t index, void *data, size_t size) {
	if (!_validate_clist(list))
		return;

	if (index > list->length)
		return;

	cnode *new_node = cnode_construct(data, size);
	if (!new_node)
		return;

	/* case 1: insert at head */
	if (index == 0) {
		if (list->length == 0) {
			list->head = new_node;
			list->tail = new_node;

			new_node->next = new_node;
			new_node->previous = new_node;
		} else {
			new_node->next = list->head;
			new_node->previous = list->tail;

			list->head->previous = new_node;
			list->tail->next = new_node;

			list->head = new_node;
		}
	}

	/* case 2: insert at tail (append) */
	else if (index == list->length) {
		list->tail->next = new_node;
		list->head->previous = new_node;

		new_node->previous = list->tail;
		new_node->next = list->head;

		list->tail = new_node;
	}

	/* case 3: insert at middle */
	else {
		cnode *on_index_node = _clist_iterate(list, index);

		new_node->previous = on_index_node->previous;
		new_node->next = on_index_node;

		on_index_node->previous->next = new_node;
		on_index_node->previous = new_node;
	}

	list->length++;
}


void clist_remove(clist *list, size_t index) {
	if (!_validate_dindex(list, index))
		return;

	cnode *target;

	/* case 1: removing the head */
	if (index == 0) {
		target = list->head;

		if (list->length < 2) {
			list->head = NULL;
			list->tail = NULL;
		} else {
			list->head = target->next;

			list->tail->next = target->next;
			list->head->previous = list->tail;
		}
	}

	/* case 2: removing the tail */
	else if (index == list->length - 1) {
		target = list->tail;

		list->tail->previous->next = list->head;
		list->head->previous = target->previous;

		list->tail = target->previous;
	}

	/* case 3: removing from middle */
	else {
		target = _clist_iterate(list, index);

		target->previous->next = target->next;
		target->next->previous = target->previous;
	}

	cnode_destruct(target);
	list->length--;
}

void* clist_fetch_data(clist *list, size_t index) {
	if (!_validate_dindex(list, index)) return NULL;

	cnode *node = _clist_iterate(list, index);
	return node ? node->data : NULL;
}

void clist_reverse(clist *list) {
	if (!_validate_clist(list) || list->length < 2) return;

	//  TODO: later

} /* clist_c */
