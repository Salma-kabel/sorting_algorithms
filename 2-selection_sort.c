#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp = 0, tmp2;

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[tmp] > array[j + 1])
				tmp = j + 1;
		}
		if (array[i] != array[tmp])
		{
			tmp2 = array[i];
			array[i] = array[tmp];
			array[tmp] = tmp2;
			print_array(array, size);
		}
		tmp = i + 1;	
	}
}
