#include "queue.h"
queue_t *queue_create(void);
void queue_push(queue_t **queue, void *ptr);
void *queue_pop(queue_t **queue);
void *queue_peek(const queue_t *queue);
int queue_empty(const queue_t *queue);
/**
 * queue_create - Create a new empty queue
 *
 * Return: A pointer to the newly created queue, or NULL on failure
 */
queue_t *queue_create(void)
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		return (NULL);
	}

	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

/**
 * queue_push - Add an element to the end of the queue
 * @queue: A pointer to the queue to which the element should be added
 * @ptr: A pointer to the data to add to the queue
 */
void queue_push(queue_t **queue, void *ptr)
{
	if (queue == NULL || ptr == NULL)
	{
		return;
	}

	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
	{
		return;
	}

	new_node->ptr = ptr;
	new_node->next = NULL;

	if ((*queue)->rear == NULL)
	{
		(*queue)->front = new_node;
		(*queue)->rear = new_node;
	}
	else
	{
		(*queue)->rear->next = new_node;
		(*queue)->rear = new_node;
	}
}

/**
 * queue_pop - Remove and return the element at the front of the queue
 * @queue: A pointer to the queue from which to remove the element
 *
 * Return: A pointer to the data at the front of the queue,
 * or NULL if the queue is empty
 */
void *queue_pop(queue_t **queue)
{
	if (queue == NULL || (*queue)->front == NULL)
	{
		return (NULL);
	}

	queue_node_t *temp = (*queue)->front;
	void *ptr = temp->ptr;

	if ((*queue)->front == (*queue)->rear)
	{
		(*queue)->front = NULL;
		(*queue)->rear = NULL;
	}
	else
	{
		(*queue)->front = (*queue)->front->next;
	}

	free(temp);
	return (ptr);
}

/**
 * queue_peek - Get the element at the front of the queue without removing it
 * @queue: A pointer to the queue
 *
 * Return: A pointer to the data at the front of the queue,
 * or NULL if the queue is empty
 */
void *queue_peek(const queue_t *queue)
{
	if (queue == NULL || queue->front == NULL)
	{
		return (NULL);
	}

	return (queue->front->ptr);
}

/**
 * queue_empty - Check if the queue is empty
 * @queue: A pointer to the queue to check
 *
 * Return: 1 if the queue is empty, 0 otherwise
 */
int queue_empty(const queue_t *queue)
{
	return (queue == NULL || queue->front == NULL);
}
