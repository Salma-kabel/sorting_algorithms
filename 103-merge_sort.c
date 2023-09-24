#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	size_t i, size2;
	int *arr;

	if (array == NULL || size == 0)
		return;
	if (size == 1)
		return;
	if (size % 2 == 0)
		size2 = size / 2;
	else
		size2 = (size / 2) + 1;
	merge_sort(array, (size / 2));
	merge_sort(array + (size / 2), size2);
	printf("Merging...\n");
	print(array, size / 2, "left");
	print(array + (size / 2), size2, "right");
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return;
	sort(array, arr, size);
	for (i = 0; i < size; i++)
		array[i] = arr[i];
	free(arr);
	print(array, size, "Done");
}

/**
 * sort - sorts an array
 * @array: array to sort
 * @arr: array to save in
 * @size: size of array
 */

void sort(int *array, int *arr, size_t size)
{
	size_t i, j = 0, k = 0;

	for (i = 0; i < size; i++)
	{
		if ((size / 2) + k < size)
		{
			if (j < size / 2)
			{
				if (array[(size / 2) + k] < array[j])
				{
					arr[i] = array[(size / 2) + k];
					k++;
				}
				else
				{
					arr[i] = array[j];
					j++;
				}
			}
			else
			{
				arr[i] = array[(size / 2) + k];
				k++;
			}
		}
		else
		{
			arr[i] = array[j];
			j++;
		}
	}
}

/**
 * print - prints to stdout
 * @array: array to print
 * @size: size of array
 * @str: string to print
 */
void print(int *array, size_t size, char *str)
{
	size_t i;

	printf("[%s]: ", str);
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
