#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/**
 * struct queue_node_s - Queue node structure
 * @ptr: Pointer to the data stored in the node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_node_s
{
	void *ptr;
	struct queue_node_s *next;
} queue_node_t;

/**
 * struct queue_s - Queue structure
 * @front: Pointer to the front of the queue
 * @rear: Pointer to the rear of the queue
 */
typedef struct queue_s
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

/* Function prototypes */
queue_t *queue_create(void);
void queue_push(queue_t **queue, void *ptr);
void *queue_pop(queue_t **queue);
int queue_empty(const queue_t *queue);
void queue_free(queue_t *queue);

#endif /* QUEUE_H */
