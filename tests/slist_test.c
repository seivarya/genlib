#include "../include/genlib/genlib.h"
#define TEC_IMPLEMENTATION
#include "tec.h/tec.h"

int main(void) {
	slist *list = slist_construct();
	int var = 69;
	slist_insert(list, 0, &var, sizeof(var));

	TEC_ASSERT(*(int *)list->head == var);
}
