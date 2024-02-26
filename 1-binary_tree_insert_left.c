#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *        If parent already has a left-child, the new node must take its place,
 *        and the old left-child must be set as the left-child of the new node.
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node,
 *         or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child, *temp;

	if (parent == NULL)
		return (NULL);

	left_child = malloc(sizeof(binary_tree_t));
	if (left_child == NULL)
		return (NULL);

	left_child->n = value;
	if (parent->left == NULL)
	{
		parent->left = left_child;
		left_child->parent = parent;
		left_child->left = NULL;
		left_child->right = NULL;
	}
	else
	{
		temp = parent->left;
		temp->parent = left_child;
		parent->left = left_child;
		left_child->parent = parent;
		left_child->left = temp;
		left_child->right = NULL;
	}

	return (left_child);
}
