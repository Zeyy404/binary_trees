#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is perfect or 0 if it is not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	if (!tree->left && !tree->right)
		return (1);

	return (left_nodes == right_nodes &&
		binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the num of nodes
 * Return: the number of nodes or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left)
			+ binary_tree_nodes(tree->right));

	return (0);
}
