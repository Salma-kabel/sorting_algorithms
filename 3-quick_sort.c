#include "sort.h"

/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int i, p, j = -1, tmp;
	static int *ptr;
	static size_t s;

	if (!ptr && !s)
	{
		ptr = array;
		s = size;
	}
	if (size == 1 || size == 0)
		return;
	{
		p = size - 1;
		for (i = 0; i < (int)size; i++)
		{
			if (array[i] <= array[size - 1])
				j++;
			if (array[j] > array[i])
			{
				if (i == (int)size - 1)
					p = j;
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(ptr, s);
			}
		}
		quick_sort(array, p);
		if (p == 0)
			quick_sort(array + 1, size - 1);
		else if (p == (int)size - 1)
			quick_sort(array, 0);
		else
			quick_sort(array + p + 1, size - (p + 1));
	}
}
