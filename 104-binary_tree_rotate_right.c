#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the binary tree to rotate
 * Return: a pointer to the new root node of the binary tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_tree = tree->left;
	tree->left = new_tree->right;
	if (new_tree->right != NULL)
		new_tree->right->parent = tree;
	new_tree->parent = tree->parent;
	new_tree->right = tree;
	tree->parent = new_tree;

	return (new_tree);
}
