#include "binary_trees.h"

/**
 * binary_tree_sibling - Возвращает указатель на брата узла
 * @node: указатель на узел, для которого ищем брата
 *
 * Return: указатель на брата, или NULL если его нет
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left && node->parent->left != node)
		return (node->parent->left);

	if (node->parent->right && node->parent->right != node)
		return (node->parent->right);
	return (NULL);
}
