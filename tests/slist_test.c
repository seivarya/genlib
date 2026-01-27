#include <genlib/genlib.h>
#include <stdio.h>

void nig_print(void *data);

typedef struct nig {
	int seq;
	size_t what; 
} nig;

void nig_print(void *data) {
	printf("=== struct nig ===\n");
	nig temp = *(nig*)data;
	printf("nig.seq -> %d\n", temp.seq);
	printf("nig.what -> %zu\n", temp.what);
}

const td TD_NIG = {
	.magic = TD_MAGIC,
	.size = sizeof(nig),
	.hash = NULL,
	.compare = NULL,
	.destruct = NULL,
	.copy = NULL,
	.print = nig_print

};


int main(void) {

	slist *list = slist_construct();

	int var = 32;
	char* str = "asdf ;lkj asdf ;lkj ";
	nig val =  {
		.seq = 32,
		.what = 32
	};

	slist_insert(list, 0, &var, &TD_INT);
	slist_insert(list, 1, str, &TD_STR);
	slist_insert(list, 2, &val, &TD_NIG);

	slist_print(list);

	slist_destruct(list);

}
