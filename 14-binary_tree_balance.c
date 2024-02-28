OB#include "binary_trees.h"

/**
 * binary_tree_balance - meauseres the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)(binary_tree_height(tree->left)
		      - binary_tree_height(tree->right)));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: the height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

	return ((left_height > right_height) ? left_height : right_height);
}
