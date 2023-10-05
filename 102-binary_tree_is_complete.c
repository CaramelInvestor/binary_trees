#include "binary_trees.h"
#include "queue.h"
/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int is_complete = 1;
	int seen_non_full = 0;

	queue_t *queue = NULL;
	queue_push(&queue, (void *)tree);

	while (!queue_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(&queue);

		if (current->left)
		{
			if (seen_non_full)
			{
				is_complete = 0;
				break;
			}
			queue_push(&queue, (void *)(current->left));
		}
		else
		{
			seen_non_full = 1;
		}

		if (current->right)
		{
			if (seen_non_full)
			{
				is_complete = 0;
				break;
			}
			queue_push(&queue, (void *)(current->right));
		}
		else
		{
			seen_non_full = 1;
		}
	}

	while (!queue_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(&queue);

		if (current->left || current->right)
		{
			is_complete = 0;
			break;
		}
	}

	queue_free(queue);

	return is_complete;
}
