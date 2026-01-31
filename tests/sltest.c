/*
 * sltest.c: thorough tests for singly linked list (slist)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rvlib/rvlib.h>

static int failures = 0;

#define CHECK(cond) do { \
	if (!(cond)) { \
		fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
		failures++; \
	} \
} while (0)

static void test_construct_destruct(void) {
	slist *list = slist_construct();
	CHECK(list != NULL);
	CHECK(list->head == NULL);
	CHECK(list->length == 0);
	slist_destruct(list);
}

static void test_empty_operations(void) {
	slist *list = slist_construct();
	CHECK(list != NULL);
	CHECK(slist_fetch_node(list, 0) == NULL);
	slist_remove(list, 0); /* no-op: empty, should not crash */
	slist_destruct(list);
}

static void test_insert_at_head(void) {
	int a = 10, b = 20, c = 30;
	slist *list = slist_construct();
	CHECK(list != NULL);

	slist_insert(list, 0, &a, &TD_INT);
	CHECK(list->length == 1);
	CHECK(((snode *)slist_fetch_node(list, 0))->data == &a);

	slist_insert(list, 0, &b, &TD_INT);
	CHECK(list->length == 2);
	CHECK(((snode *)slist_fetch_node(list, 0))->data == &b);
	CHECK(((snode *)slist_fetch_node(list, 1))->data == &a);

	slist_insert(list, 0, &c, &TD_INT);
	CHECK(list->length == 3);
	CHECK(((snode *)slist_fetch_node(list, 0))->data == &c);
	CHECK(((snode *)slist_fetch_node(list, 1))->data == &b);
	CHECK(((snode *)slist_fetch_node(list, 2))->data == &a);

	slist_destruct(list);
}

static void test_insert_at_tail(void) {
	int a = 1, b = 2, c = 3;
	slist *list = slist_construct();
	CHECK(list != NULL);

	slist_insert(list, 0, &a, &TD_INT);
	slist_insert(list, 1, &b, &TD_INT);
	slist_insert(list, 2, &c, &TD_INT);
	CHECK(list->length == 3);
	CHECK(((snode *)slist_fetch_node(list, 0))->data == &a);
	CHECK(((snode *)slist_fetch_node(list, 1))->data == &b);
	CHECK(((snode *)slist_fetch_node(list, 2))->data == &c);

	slist_destruct(list);
}

static void test_insert_at_middle(void) {
	int a = 1, b = 2, c = 3, x = 99;
	slist *list = slist_construct();
	slist_insert(list, 0, &a, &TD_INT);
	slist_insert(list, 1, &b, &TD_INT);
	slist_insert(list, 2, &c, &TD_INT);
	CHECK(list->length == 3);

	slist_insert(list, 1, &x, &TD_INT);
	CHECK(list->length == 4);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 1);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 1))->data == 99);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 2))->data == 2);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 3))->data == 3);

	slist_destruct(list);
}

static void test_remove_head(void) {
	int a = 1, b = 2, c = 3;
	slist *list = slist_construct();
	slist_insert(list, 0, &a, &TD_INT);
	slist_insert(list, 1, &b, &TD_INT);
	slist_insert(list, 2, &c, &TD_INT);

	slist_remove(list, 0);
	CHECK(list->length == 2);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 2);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 1))->data == 3);

	slist_remove(list, 0);
	CHECK(list->length == 1);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 3);

	slist_remove(list, 0);
	CHECK(list->length == 0);
	CHECK(list->head == NULL);

	slist_destruct(list);
}

static void test_remove_tail(void) {
	int a = 1, b = 2, c = 3;
	slist *list = slist_construct();
	slist_insert(list, 0, &a, &TD_INT);
	slist_insert(list, 1, &b, &TD_INT);
	slist_insert(list, 2, &c, &TD_INT);

	slist_remove(list, 2);
	CHECK(list->length == 2);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 1);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 1))->data == 2);

	slist_remove(list, 1);
	CHECK(list->length == 1);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 1);

	slist_destruct(list);
}

static void test_remove_middle(void) {
	int a = 1, b = 2, c = 3;
	slist *list = slist_construct();
	slist_insert(list, 0, &a, &TD_INT);
	slist_insert(list, 1, &b, &TD_INT);
	slist_insert(list, 2, &c, &TD_INT);

	slist_remove(list, 1);
	CHECK(list->length == 2);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 1);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 1))->data == 3);

	slist_destruct(list);
}

static void test_fetch_node_out_of_bounds(void) {
	int a = 1;
	slist *list = slist_construct();
	slist_insert(list, 0, &a, &TD_INT);
	CHECK(slist_fetch_node(list, 1) == NULL);
	CHECK(slist_fetch_node(list, 99) == NULL);
	slist_destruct(list);
}

static void test_single_element(void) {
	int x = 42;
	slist *list = slist_construct();
	slist_insert(list, 0, &x, &TD_INT);
	CHECK(list->length == 1);
	CHECK(*(int *)((snode *)slist_fetch_node(list, 0))->data == 42);
	slist_remove(list, 0);
	CHECK(list->length == 0);
	slist_destruct(list);
}

static void test_print_empty(void) {
	slist *list = slist_construct();
	slist_print(list); /* should not crash; may print error to stderr */
	slist_destruct(list);
}

static void test_print_non_empty(void) {
	int a = 1, b = 2;
	slist *list = slist_construct();
	slist_insert(list, 0, &a, &TD_INT);
	slist_insert(list, 1, &b, &TD_INT);
	slist_print(list); /* should not crash */
	slist_destruct(list);
}

static void test_destruct_null(void) {
	slist_destruct(NULL); /* should not crash */
}

static void test_insert_append_sequence(void) {
	slist *list = slist_construct();
	int vals[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (size_t i = 0; i < 10; i++)
		slist_insert(list, i, &vals[i], &TD_INT);
	CHECK(list->length == 10);
	for (size_t i = 0; i < 10; i++)
		CHECK(*(int *)((snode *)slist_fetch_node(list, i))->data == (int)i);
	slist_destruct(list);
}

int main(void) {
	test_construct_destruct();
	test_empty_operations();
	test_insert_at_head();
	test_insert_at_tail();
	test_insert_at_middle();
	test_remove_head();
	test_remove_tail();
	test_remove_middle();
	test_fetch_node_out_of_bounds();
	test_single_element();
	test_print_empty();
	test_print_non_empty();
	test_destruct_null();
	test_insert_append_sequence();

	if (failures > 0) {
		fprintf(stderr, "sltest: %d failure(s)\n", failures);
		return 1;
	}
	printf("sltest: all tests passed\n");
	return 0;
}
