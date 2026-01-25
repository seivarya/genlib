#include "../include/genlib/genlib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	dlist *list = dlist_construct();
	int var = 32;
	dlist_insert(list, 0, &var, sizeof(var));
	printf("%d\n", *(int*)dlist_fetch_data(list, 0));
	dlist_destruct(list);
}
