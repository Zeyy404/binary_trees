#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a bianry tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_tree;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_tree = tree->right;
	tree->right = new_tree->left;
	if (new_tree->left != NULL)
		new_tree->left->parent = tree;
	new_tree->parent = tree->parent;
	tree->parent = new_tree;
	new_tree->left = tree;

	return (new_tree);
}
