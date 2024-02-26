#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *       If parent already has a right-child, the new node must take its place,
 *      and the old right-child must be set as the right-child of the new node.
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node,
 *         or NULL on failure or if the parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	right_child->n = value;
	if (parent->right == NULL)
	{
		parent->right = right_child;
		right_child->parent = parent;
		right_child->left = NULL;
		right_child->right = NULL;
	}
	else
	{
		right_child->right = parent->right;
		right_child->right->parent = right_child;
		parent->right = right_child;
		right_child->parent = parent;
		right_child->left = NULL;
	}

	return (right_child);
}
