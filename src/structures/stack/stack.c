// ====================
// | > stack_node.c |
// ====================

#include "stack.h"

struct stack_node* stack_node_create(struct stack *self, void *data, size_t size);

void stack_push(struct stack *self, void *data, size_t size);
void stack_pop(struct stack *self);
bool stack_is_empty(struct stack *self);
void* stack_peek(struct stack *self);


struct stack stack_construct(void) {
	struct stack stack = {
		.head = NULL,
		.length = 0,

		.push = stack_push,
		.pop = stack_pop,
		.is_empty = stack_is_empty,
		.peek = stack_peek
	};

	return stack;
}

void stack_destruct(struct stack *stack) {
	if (!stack) return;
	if (!stack->head || stack->head == NULL) return;
	if (stack->length == 1) {
		stack_node_destruct(stack->head);	
		stack->head = NULL;
		stack->length = 0;
		return;
	}
	struct stack_node *current = stack->head;
	struct stack_node *next = NULL;
	while(current != NULL) {
		next = current->next;
		stack_node_destruct(current);
		current = next;
	}
	stack->head = NULL;
	stack->length = 0;
}

struct stack_node* stack_node_create(struct stack *self, void *data, size_t size) {
	if (!(self)) return NULL;
	struct stack_node *node = malloc(sizeof(struct stack_node));
	if (!node) {
		perror("=== stack_node_create(): malloc failed ===\n");
	}
	*node = stack_node_construct(size, data);
	return node;
}

void stack_push(struct stack *self, void *data, size_t size) {
	if (stack_validate(self) == 0) return;

	struct stack_node *node_to_insert = stack_node_create(self, data, size);
	if (self->length == 0) {
		self->head = node_to_insert;
		node_to_insert->next = NULL;
	} else {
		node_to_insert->next = self->head;
		self->head = node_to_insert;
	}
	self->length++;
}

void stack_pop(struct stack *self) {
	if (stack_validate(self) == 0) return;
	if (self->length == 0) return;

	struct stack_node *node_to_remove = self->head;
	if (self->length == 1) {
		self->head = NULL;
	} else {
		self->head = node_to_remove->next;
	}
	stack_node_destruct(node_to_remove);
	self->length--;
}

bool stack_is_empty(struct stack *self) {
	if (stack_validate(self) == 0) return false;
	if (stack_head_validate(self) == 0) return false;

	if (self->length == 0) {
		return true;
	}
	return false;
}

void* stack_peek(struct stack *self) {
	if (stack_validate(self) == 0) return NULL;
	if (stack_head_validate(self) == 0) return NULL;
	return self->head->data;
} /* stack_c */
