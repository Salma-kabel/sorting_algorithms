#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: head of linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int size = 1, count = 0;

	if (list == NULL || *list == NULL)
		return;
	ptr = *list;
	while (size > 0)
	{
		while (ptr->next != NULL && size > 0)
		{
			if (count == 0)
				size++;
			if (ptr->n > ptr->next->n)
			{
				if (ptr->prev == NULL)
					*list = ptr->next;
				else
					ptr->prev->next = ptr->next;
				if (ptr->next->next != NULL)
					ptr->next->next->prev = ptr;
				ptr->next->prev = ptr->prev;
				ptr->prev = ptr->next;
				ptr->next = ptr->prev->next;
				ptr->prev->next = ptr;
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		size--;
		count = 1;
		ptr = ptr->prev;
		ptr = forward(list, ptr, size);
		size--;
	}
}

/**
 * forward - moves smallest element to the beginning
 * @list: head of the list
 * @ptr: pointer to last element
 * @size: size of elements left
 * Return: pointer to first element after moving
 */
listint_t *forward(listint_t **list, listint_t *ptr, int size)
{
	while (ptr->prev != NULL && size > 0)
	{
		size--;
		if (ptr->n < ptr->prev->n)
		{
			if (ptr->prev->prev == NULL)
				*list = ptr;
			else
				ptr->prev->prev->next = ptr;
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = ptr->prev->prev;
			ptr->next->prev = ptr;
			print_list(*list);
		}
		else
			ptr = ptr->prev;
	}
	ptr = ptr->next;
	return (ptr);
}
