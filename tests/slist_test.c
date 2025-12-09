// =======================
// | test: singly_test.c |
// =======================

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/genlib/genlib.h"

int main(void) {
	slist *list = slist_construct();
	char *str = "hey! i've been refactored like a -";
	slist_insert(list, 0, str, strlen(str) + 1); 
	char *fetched = (char *)list->head->data;
	printf("string: %s\n", fetched);
}
