#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
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

/**
 * _is_perfect - Checks if a binary tree is perfect recursively
 * @tree: Pointer to the root node of the tree
 * @depth: Depth of the tree
 * @level: Current level of the node
 *
 * Return: 1 if perfect, 0 if not
 */
static int _is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (_is_perfect(tree->left, depth, level + 1) &&
		_is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if perfect, 0 if not or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = _height(tree);

	return (_is_perfect(tree, depth, 0));
}
