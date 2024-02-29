#include "binary_trees.h"

int is_bst_recursive(const binary_tree_t *node, const int *min, const int *max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary seach tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_recursive(tree, NULL, NULL));
}

/**
 * is_bst_recursive - recursively checks if a binary tree is a valid BST
 * @node: a pointer to the current node
 * @min: the minimum value allowed for the current node (exclusive)
 * @max: the maximum value allowed for the current node (exclusive)
 * Return: 1 if the tree rooted at node is a valid BST, 0 otherwise
 */
int is_bst_recursive(const binary_tree_t *node, const int *min, const int *max)
{
	if (node == NULL)
		return (1);

	if ((min != NULL && node->n < *min) || (max != NULL && node->n > *max))
		return (0);

	return (is_bst_recursive(node->left, min, &node->n) &&
		is_bst_recursive(node->right, &node->n, max));
}
