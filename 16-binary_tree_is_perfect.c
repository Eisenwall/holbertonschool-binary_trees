#include "binary_trees.h"

/**
 * _height - Возвращает высоту дерева (кол-во узлов по максимальному пути)
 * @tree: указатель на корень дерева
 *
 * Return: высота, 0 если tree == NULL
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = _height(tree->left);
	right_height = _height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
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
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = _height(tree);

	return (_is_perfect(tree, depth, 0));
}
