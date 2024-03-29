#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using postorder traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call each node,
 *     the value in each node shall be passed as a parameter to this function
 * if tree or func is NULL, do nothing
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
