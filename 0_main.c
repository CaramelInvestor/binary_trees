#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
	binary_tree_t *root; // Use a pointer to binary_tree_t

	root = binary_tree_node(NULL, 180);
	if (!root)
	{
		printf("binary_tree_node returned NULL\n");
		return (1);
	}
	printf("Parent: %p\n", (void *)(root->parent)); // Access parent, left, and right using -> notation
	printf("Left: %p\n", (void *)(root->left));
	printf("Right: %p\n", (void *)(root->right));
	binary_tree_print(root);
	binary_tree_delete(root); // Use the correct function name
	return (0);
}
