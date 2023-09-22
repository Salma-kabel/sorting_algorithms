#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swap = 0, var;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				var = array[j];
				array[j] = array[j + 1];
				array[j + 1] = var;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
