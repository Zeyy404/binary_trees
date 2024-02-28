#include "binary_trees.h"

int binary_tree_is_descendant(const binary_tree_t *ancestor,
			      const binary_tree_t *descendant);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer the the lowest common ancestor node
 * of the two given nodes, Otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor = first;

	while (ancestor != NULL)
	{
		if (binary_tree_is_descendant(ancestor, second))
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_descendant - checks if a node is a descendant of another node
 * @ancestor: a pointer to the potential ancestor node
 * @descendant: a pointer to the potential descendant node
 * Return: 1 if descendant is a descendant of ancestor, 0 otherwise
 */
int binary_tree_is_descendant(const binary_tree_t *ancestor,
			      const binary_tree_t *descendant)
{
	while (descendant != NULL)
	{
		if (descendant == ancestor)
			return (1);
		descendant = descendant->parent;
	}
	return (0);
}
