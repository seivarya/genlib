#include "../include/genlib/genlib.h"

// slist* slist_construct(void);
// void slist_destruct(slist *slist);
//
// void slist_insert(slist *self, size_t index, void *data, size_t size);
// void slist_remove(slist *self, size_t index);
// void slist_reverse(slist *self);
//
// void* slist_fetch_data(slist *self, size_t index);


int main(void) {
	slist *list = slist_construct();
	int var = 69;
	slist_insert(list, 0, &var, sizeof(var));
	slist_remove(list, 0);
	slist_destruct(list);
}
