#include "binary_trees.h"

bst_t *bst_find_successor(bst_t *root);

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Once located, the node containing a value equals to value
 *     must be removed and freed
 * If the node to be deleted has two children,
 *     it must be replaced with its first in-order successor (not predecessor)
 * Return: a pointer to the new root node of the tree
 *     after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}

		temp = bst_find_successor(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * bst_find_successor - finds the node with the minimum value in a BST
 * @root: a pointer to the root node of the BST
 * Return: a pointer to the node with the minimum value
 */
bst_t *bst_find_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}
