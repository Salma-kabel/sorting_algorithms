#include "sort.h"

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int i, size2 = 0, *arr, *arr2;

	if (array == NULL || size <= 0)
		return;
	arr2 = malloc(sizeof(int) * size);
	for (i = 0; i < (int)size; i++)
	{
		arr2[i] = array[i];
		if (size2 < array[i])
			size2 = array[i];
	}
	size2++;
	arr = malloc(sizeof(int) * size2);
	for (i = 0; i < size2; i++)
		arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		arr[array[i]]++;
	for (i = 0; i < size2; i++)
	{
		if (i > 0)
		{
			arr[i] = arr[i - 1] + arr[i];
			printf(", ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
	for (i = size2 - 1; i >= 0; i--)
	{
		if (i == 0)
			arr[i] = 0;
		else
			arr[i] = arr[i - 1];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[arr[arr2[i]]] = arr2[i];
		arr[arr2[i]]++;
	}
	free(arr);
	free(arr2);
}
