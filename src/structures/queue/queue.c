// ====================
// |    > queue.c     |
// ====================

#include "queue.h"

struct queue_node* queue_node_create(struct queue *self, void *data, size_t size);

void queue_enqueue(struct queue *self, void *data, size_t size);
void queue_dequeue(struct queue *self);
bool queue_is_empty(struct queue *self);

void* queue_get_front(struct queue *self);
void* queue_get_rear(struct queue *self);

struct queue queue_construct(void) {
	struct queue queue = {
		.head = NULL,
		.tail = NULL,
		.length = 0,
		.enqueue = queue_enqueue,
		.dequeue = queue_dequeue,
		.is_empty = queue_is_empty,
		.get_front = queue_get_front,
		.get_rear = queue_get_rear
	};
	return queue;
}

void queue_destruct(struct queue *queue) {
	if (queue_validate(queue) == 0) return;

	if (queue->length == 1) {
		queue_node_destruct(queue->head);
		queue->length = 0;
		queue->head = NULL;
		queue->tail = NULL;
		return;
	}
	struct queue_node *current = queue->head;
	struct queue_node *next = NULL;
	while(current != NULL) {
		next = current->next;
		queue_node_destruct(current);
		current = next;
	}
	queue->head = NULL;
	queue->length = 0;
	queue->tail = NULL;
}

struct queue_node * queue_node_create(struct queue *self, void *data, size_t size) {
	if (queue_validate(self) == 0) return NULL;
	struct queue_node *node = malloc(sizeof(struct queue_node));
	if (!node) {
		perror("=== queue_node_create(): malloc failed ===\n");
	}
	*node = queue_node_construct(data, size);
	return node;
}

void queue_enqueue(struct queue *self, void *data, size_t size) {
	if (queue_validate(self) == 0) return;
	struct queue_node *node_to_insert = queue_node_create(self, data, size);
	if (self->length == 0) {
		self->head = node_to_insert;
		self->tail = node_to_insert;
	} else {
		self->tail->next = node_to_insert;
		self->tail = node_to_insert; 
	}
	self->length++;
}

void queue_dequeue(struct queue *self) {
	if (queue_validate(self) == 0) return;
	if (self->head == NULL) return;

	struct queue_node *node_to_remove = self->head;
	if (self->length == 1) {
		self->head = NULL;
		self->tail = NULL;
	} else {
		self->head = node_to_remove->next;
	}
	self->length--;
	queue_node_destruct(node_to_remove);
}

bool queue_is_empty(struct queue *self) {
	if (queue_validate(self) == 0) return true;
	return self->length == 0;
}

void* queue_get_front(struct queue *self) {
	if (queue_validate(self) == 0) return NULL;
	return self->head->data;
}

void* queue_get_rear(struct queue *self) {
	if (queue_validate(self) == 0) return NULL;
	return self->tail->data;
} /* queue_c */
