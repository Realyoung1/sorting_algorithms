#include "sort.h"

#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an arrayss
 * @a: The first integer to swapss
 * @b: The second integer to swapss
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heapss
 * @array: An array of integers representing a binary treess
 * @size: The size of the array/treess
 * @base: The index of the base row of the treess
 * @root: The root node of the binary treess
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascendingss
 *             order using the heap sort algorithmss
 * @array: An array of integersss
 * @size: The size of the arrays
 *
 * Description: Implements the sift-down heap sortss
 * algorithm. Prints the array after each swapss
 */

void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = (size / 2) - 1; j >= 0; j--)
		max_heapify(array, size, size, j);

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		max_heapify(array, size, j, 0);
	}
}
