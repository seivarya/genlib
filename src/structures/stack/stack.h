// ====================
// | > stack_node.h |
// ====================

#include "snode/snode.h"
#include <stdbool.h>

struct stack {
	struct stack_node *head;
	size_t length;

	void (*push)(struct stack *self, void *data, size_t size);
	void (*pop)(struct stack *self);
	bool (*is_empty)(struct stack *self);
	void* (*peek)(struct stack *self);
};

struct stack stack_construct(void);
void stack_destruct(struct stack *stack);

static inline int stack_validate(struct  stack *stack) {
	if (stack) return 1;
	printf("=== stack_validate(): failed ===\n");
	return 0;
}

static inline int stack_head_validate(struct stack *stack) {
	if (stack->head) return 1;
	printf("=== stack_head_validate(): failed ===\n");
	return 0;
} /* stack_h */
