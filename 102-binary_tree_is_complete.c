#include "binary_trees.h"

int is_complete_recursive(const binary_tree_t *node, int index,
			  int count, size_t size);

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is complete or 0 if it is not or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete_recursive(tree, 0, 0, binary_tree_size(tree)));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: the size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left)
		+ binary_tree_size(tree->right));
}

/**
 * is_complete_recursive - recursively checks if binary tree is complete
 * @node: a pointer to the current node
 * @index: the index of the current node
 * @count: the count of the non-NULL nodes from the leftmost side
 * @size: the total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *node, int index,
			  int count, size_t size)
{
	if (node == NULL)
		return (1);

	if (index >= (int)size)
		return (0);

	return (is_complete_recursive(node->left, 2 * index + 1, count, size) &&
		is_complete_recursive(node->right, 2 * index + 2,
				      count + 1, size));
}
