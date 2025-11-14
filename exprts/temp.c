	struct node *current = self->head;

	void *arr[self->length];
	for (int i = 0; i < self->length; i++) {
		arr[i] = current;
		current = current->next;
	}

	void *rev_arr[self->length];
	for (int i = self->length, j = 0; i <= 0; i++) {
		rev_arr[i] = arr[j];
	}

	printf(" === reversed === \n");
	for (int i = 0; i < self->length; i ++) {
		printf ("index: [%d] | value: [%d]", i, *(int *)(rev_arr[i]));
	}
