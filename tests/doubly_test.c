
#include "../src/structures/list/doubly/doubly_list.h"

struct doubly_node *iterate(struct doubly *self, size_t index);


int main(void) {
	struct doubly list = doubly_construct();

	char *fir_val = "this";
	char *sec_val = "is";
	char *thi_val = "a";
	char *fou_val = "test";
	char *fif_val = "sir.";

	list.insert(&list, 0, fir_val, strlen(fir_val));
	list.insert(&list, 1, sec_val, strlen(sec_val));
	list.insert(&list, 2, thi_val, strlen(thi_val));
	list.insert(&list, 3, fou_val, strlen(fou_val));
	list.insert(&list, 4, fif_val, strlen(fif_val));

	printf("LENGTH: %zu\n", list.length);
	printf("first value: %s\n", (char *)list.fetch_data(&list, 0));
	printf("second value: %s\n", (char *)list.fetch_data(&list, 1));
	printf("third: %s\n", (char *)list.fetch_data(&list, 2));
	printf("fourth: %s\n", (char *)list.fetch_data(&list, 3));
	printf("fifth: %s\n", (char *)list.fetch_data(&list, 4));

	printf("=== middle insertion ===\n");

	list.insert(&list, 2, "the", strlen("the"));

	printf("first value: %s\n", (char *)list.fetch_data(&list, 0));
	printf("second value: %s\n", (char *)list.fetch_data(&list, 1));
	printf("third: %s\n", (char *)list.fetch_data(&list, 2));
	printf("fourth: %s\n", (char *)list.fetch_data(&list, 3));
	printf("fifth: %s\n", (char *)list.fetch_data(&list, 4));
	printf("sixth: %s\n", (char *)list.fetch_data(&list, 5));


	printf("=== removal ===\n");

	list.remove(&list, 5);

	printf("first value: %s\n", (char *)list.fetch_data(&list, 0));
	printf("second value: %s\n", (char *)list.fetch_data(&list, 1));
	printf("third: %s\n", (char *)list.fetch_data(&list, 2));
	printf("fourth: %s\n", (char *)list.fetch_data(&list, 3));
	printf("fifth: %s\n", (char *)list.fetch_data(&list, 4));

	list.reverse(&list);

	printf("first value: %s\n", (char *)list.fetch_data(&list, 0));
	printf("second value: %s\n", (char *)list.fetch_data(&list, 1));
	printf("third: %s\n", (char *)list.fetch_data(&list, 2));
	printf("fourth: %s\n", (char *)list.fetch_data(&list, 3));
	printf("fifth: %s\n", (char *)list.fetch_data(&list, 4));

	return 0;
}
