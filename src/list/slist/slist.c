/* src/list/slist/slist.c */
#include <stdlib.h>
#include <stdio.h>
#include "snode.h" 
#include "../../../include/genlib/slist.h"

// ==========================================
//    	  internal helper functions
// ==========================================

static inline int _validate_list(struct slist *list) {
	if (list == NULL) {
		fprintf(stderr, "error: list doesn't exist or it has been destroyed");
		return 0;
	}
	return 1;
}

static inline int _validate_index(struct slist *list, size_t index) {
    if (!list || index >= list->length) {
        fprintf(stderr, "error: index [%zu] out of bounds <length: %zu>\n", index, list->length);
        return 0;
    }
    return 1;
}

static struct snode* _slist_iterate(struct slist *list, size_t index) {
    if (!_validate_index(list, index)) return NULL;
    
    struct snode *cursor = list->head;
    for (size_t i = 0; i < index; i++) {
        cursor = cursor->next;
    }
    return cursor;
}

// ==========================================
//   	      public methods
// ==========================================

struct slist* slist_construct(void) {
    struct slist *list = malloc(sizeof(struct slist));
    if (list) {
        list->head = NULL;
        list->length = 0;
    }
    return list;
}

void slist_destruct(struct slist *list) {
    if (!_validate_list(list)) return;

    struct snode *current = list->head;
    while (current != NULL) {
        struct snode *next = current->next;
        snode_destruct(current);
        current = next;
    }
    free(list);
}

void slist_insert(struct slist *list, size_t index, void *data, size_t size) {
    if (!_validate_list(list)) return;
    if (index > list->length) return; 

    struct snode *new_node = snode_construct(data, size);
    if (!new_node) return;

    if (index == 0) {
        new_node->next = list->head; 
        list->head = new_node;
    } else {
        struct snode *previous = _slist_iterate(list, index - 1);
        new_node->next = previous->next;
        previous->next = new_node;
    }

    list->length++;
}

void slist_remove(struct slist *list, size_t index) {
    if (!_validate_index(list, index)) return;

    struct snode *target;

    if (index == 0) {
        target = list->head;
        list->head = target->next;
    } else {
        struct snode *previous = _slist_iterate(list, index - 1);
        target = previous->next;
        previous->next = target->next;
    }
    
    snode_destruct(target);
    list->length--;
}

void* slist_fetch_data(struct slist *list, size_t index) {
    struct snode* node = _slist_iterate(list, index);
    return node ? node->data : NULL;
}

void slist_reverse(struct slist *list) {
    if (!_validate_list(list) || list->length < 2) return;

    struct snode *previous = NULL;
    struct snode *current = list->head;
    struct snode *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list->head = previous;
} /* slist_c */
