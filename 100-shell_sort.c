#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	int h = 1, tmp, k, j;

	if (array == NULL || size <= 0)
		return;
	while ((h * 3 + 1) < (int)size)
		h = h * 3 + 1;
	while (h >= 1)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (j + h < (int)size && array[j] > array[j + h])
			{
				tmp = array[j + h];
				array[j + h] = array[j];
				array[j] = tmp;
				k = j;
				while (k - h >= 0 && array[k] < array[k - h])
				{
					tmp = array[k - h];
					array[k - h] = array[k];
					array[k] = tmp;
					k = k - h;
				}
			}
		}
		print_array(array, size);
		h = (h) / 3;
	}
}
