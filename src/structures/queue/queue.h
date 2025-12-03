// ====================
// |    > queue.h     |
// ====================

#include "queue_node/queue_node.h"
#include <stdbool.h>

struct queue {
	struct queue_node *head;
	struct queue_node *tail;
	size_t length;

	void (*enqueue)(struct queue *self, void *data, size_t size);
	void (*dequeue)(struct queue *self);
	bool (*is_empty)(struct queue *self);

	void* (*get_front)(struct queue *self);
	void* (*get_rear)(struct queue *self);
};

struct queue queue_construct(void);
void queue_destruct(struct queue *queue);

static int queue_validate(struct queue *queue) {
	return 0;
}

static int queue_head_validate(struct queue *queue) {
	return 0;
} /* queue_h */
