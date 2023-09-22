#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *ptr2;

	ptr = *list;
	ptr2 = *list;
	while (ptr != NULL)
	{
		ptr2 = ptr->next;
		while (ptr->prev != NULL && ptr->n < ptr->prev->n)
		{
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			if (ptr->prev->prev == NULL)
				*list = ptr;
			else
				ptr->prev->prev->next = ptr;
			ptr->prev->next = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = ptr->prev->prev;
			ptr->next->prev = ptr;
			print_list(*list);
		}
		ptr = ptr2;
	}
}
