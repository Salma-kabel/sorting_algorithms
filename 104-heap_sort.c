#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	size_t i, j, size2;
	int tmp;

	if (array == NULL || size <= 0)
		return;
	i = size - 1;
	while (i > 0)
	{
		j = (i - 1) / 2;
		if ((i - 1) % 2 != 0)
		{
			if (array[i] < array[i - 1] && array[i - 1] > array[j])
			{
				i--;
				continue;
			}
		}
		if (array[i] > array[j])
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			i = size - 1;
			print_array(array, size);
		}
		else
			i--;
	}
	size2 = size;
	while (size > 1)
	{
		tmp = array[size - 1];
		array[size - 1] = array[0];
		array[0] = tmp;
		print_array(array, size2);
		size--;
		i = 0;
		j = 2 * i + 1;
		while ((j < size && array[i] < array[j]) || ( j + 1 < size && array[i] < array[j + 1]))
		{
			tmp = array[i];
			if (j + 1 < size && array[i] < array[j + 1])
			{
				if (j < size)
				{
				      if (array[j + 1] > array[j])
					      j = j + 1;
				}
				else
					j = j + 1;
			}
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size2);
			i = j;
			j = 2 * i + 1;
		}
	}
}
