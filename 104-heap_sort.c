#include "sort.h"



void heap_sort(int *array, size_t size)
{
	tree *head, *ptr, *node = NULL;

	if (array == NULL || size <= 0)
		return;
	head = create(node, 0, array[0], NULL);
	for (i = 0; i < (int)size; i++)
	{
		ptr->left = create(node, i, array[i], ptr);
		if (i + 1 < size)
			ptr->right = create(node, i + 1, array[i + 1], ptr);
		if (ptr->parent != NULL)
		{
		       if (ptr = ptr->parent->left)
			       ptr = ptr->parent->right;
		       else if (ptr = ptr->parent->parent->left)
			       ptr =ptr->parent->parent->right->left;
		       else
			       ptr = ptr->parent->parent->left->left->left;
		}
		else
			ptr = ptr->left;
	}
}

tree *create(tree *node, int i, int v, tree *p)
{
	node = malloc(sizeof(tree));
	if (node == NULL)
	{
		free;
		return;
	}
	node->location = i;
	node->value = v;
	node->parent = p;
	node->left = NULL;
	node->right = NULL;
	return node;
}
