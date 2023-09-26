#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct tree - tree node
 * @location: location of element in array
 * @value: value of element
 * @left: Pointer to the left element of the tree
 * @right: pointer to the right element of the tree
 */

typedef struct tree
{
	int location;
	int value;
	struct tree *left;
	struct tree *right;
} tree;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *forward(listint_t **list, listint_t *ptr, int size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void print(int *array, size_t size, char *str);
void sort(int *array, int *arr, size_t size);
void heap_sort(int *array, size_t size);
void initial_sort(int *array, size_t i, size_t size);
#endif
