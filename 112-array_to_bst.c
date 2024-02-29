#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 * Return: a pointer to the root node of the created BST, or NULL in failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t counter;

	if (array == NULL || size == 0)
		return (NULL);

	for (counter = 0; counter < size; counter++)
	{
		if (!bst_insert(&tree, array[counter]))
			continue;
	}
	return (tree);
}
