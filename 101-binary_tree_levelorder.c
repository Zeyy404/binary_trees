#include "binary_trees.h"

void binary_tree_level(const binary_tree_t *tree,
		       void (*func)(int), int level);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - goes through a bianry tree using
 *                             level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call each node.
 *    The value in the nodes should be passed as parameter to this function.
 * if tree or func is NULL, do nothing
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (level = 1; level <= height; level++)
		binary_tree_level(tree, func, level);
}

/**
 * binary_tree_level - processes nodes at a certain level
 * @tree: a pointer to the root node of the binary tree
 * @func: a pointer to a function to call for each node
 * @level: the level to process
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level(tree->left, func, level - 1);
		binary_tree_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree
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
