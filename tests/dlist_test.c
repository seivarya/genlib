#include "../include/genlib/genlib.h"
#include <stdio.h>

int main(void) {
	dlist *list = dlist_construct();
	int var = 32;
	dlist_insert(list, 0, &var, NULL);
	dlist_destruct(list);
}
