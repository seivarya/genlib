#include "../include/genlib/genlib.h"

int main(void) {

	slist *list = slist_construct();

	int var = 32;
	char* str = "asdf ;lkj asdf ;lkj ";

	slist_insert(list, 0, &var, &TD_INT);
	slist_insert(list, 1, str, &TD_STR);

	list->head->type->print(list->head->data);
	list->head->next->type->print(list->head->next->data);

	slist_destruct(list);

}
