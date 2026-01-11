#include "td.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

td* td_construct(char *name) {
	struct td *type_descriptor = malloc(sizeof(td));

	if (strcmp(name, "int")) {
		type_descriptor->print = int_print;
	}
	return NULL;
}

void int_print(void *data) {
	printf("%d\n", *(int *)data);
}

void td_destruct(td *td) {
}


