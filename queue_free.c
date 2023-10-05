#include "queue.h"

/**
 * queue_free - Free the memory allocated for the queue and its elements
 * @queue: A pointer to the queue to free
 */
void queue_free(queue_t *queue)
{
	if (queue == NULL)
	{
		return;
	}

	while (!queue_empty(queue))
	{
		queue_pop(&queue);
	}

	free(queue);
}
