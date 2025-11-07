#include <stdio.h>
#include "../src/node/node.h"

int main(void) {
	int val = 23;
	struct node node = (struct node)(node_construct(&val, sizeof(int)));

	int test = (int)node.data;

	printf("%d\n", test);
}
