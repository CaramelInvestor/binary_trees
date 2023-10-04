#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *f_tmp, *s_tmp;
	size_t f_depth, s_depth;

	if (!first || !second)
		return (NULL);
	f_tmp = first;
	s_tmp = second;
	f_depth = s_depth = 0;
	while (f_tmp->parent)
	{
		f_tmp = f_tmp->parent;
		f_depth++;
	}
	while (s_tmp->parent)
	{
		s_tmp = s_tmp->parent;
		s_depth++;
	}
	f_tmp = first;
	s_tmp = second;

	while (f_depth > s_depth)
	{
		f_tmp = f_tmp->parent;
		f_depth--;
	}
	while (s_depth > f_depth)
	{
		s_tmp = s_tmp->parent;
		s_depth--;
	}
	while (f_tmp && s_tmp)
	{
		if (f_tmp == s_tmp)
			return ((binary_tree_t *)f_tmp);
		f_tmp = f_tmp->parent;
		s_tmp = s_tmp->parent;
	}
	return (NULL);
}
