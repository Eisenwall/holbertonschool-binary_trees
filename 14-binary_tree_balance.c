#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree node
 * @tree: Pointer to the node to measure balance factor
 *
 * Return: Balance factor (left subtree height - right subtree height), or
 * 0 if tree is NULL
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = _height(tree->left);
	right_height = _height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)_height(tree->left) - (int)_height(tree->right));
}
