#include <stdio.h>

#include "../src/structures/list/singly/singly_list.h"
#include "../src/structures/list/doubly/doubly_list.h"


int main(void) {
	struct singly singly_list = singly_construct();
	struct doubly doubly_list = doubly_construct();
	printf("=== compilation succesfull ===\n");

	return 0;
}
