#include "bst.h"





struct bst bst_construct(int *(compare)(void *data_fir, void *data_sec)) {
	struct bst bst;
	bst.head = NULL;
	bst.length = 0;

	return bst;
}

void bst_destruct(struct bst *bst) {
	
}


/* bst_c */
