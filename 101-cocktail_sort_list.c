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
	do
	{
		while (ptr->next != NULL)
		{
			if (count == 0)
				size++;
			else
				size--;
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
			}
			else
				ptr = ptr->next;
			count = 1;
		}
		ptr = ptr->prev;
		while (ptr->prev != NULL)
		{
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
			}
			else
				ptr = ptr->prev
		}
	}
}
