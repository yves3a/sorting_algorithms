#include "sort.h"
#include <stdio.h>

/**
 * swap_elements - Swaps two elements in an array
 * @array: Array containing elements
 * @i: First index
 * @j: Second index
 */
void swap_elements(int *array, size_t i, size_t j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_compare - Compare and swap elements in bitonic sequence
 * @array: Array to sort
 * @start: Starting index of sequence
 * @seq: Length of sequence
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t start, size_t seq, int dir)
{
	size_t jump = seq / 2;
	size_t i;

	for (i = start; i < start + jump; i++)
	{
		if ((array[i] > array[i + jump]) == dir)
			swap_elements(array, i, i + jump);
	}
}

/**
 * bitonic_merge - Recursively merge bitonic sequences
 * @array: Array to sort
 * @start: Starting index of sequence
 * @seq: Length of sequence
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 * @size: Total size of original array
 */
void bitonic_merge(int *array, size_t start, size_t seq, int dir, size_t size)
{
	size_t k = seq / 2;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size,
				dir ? "UP" : "DOWN");
		print_array(array + start, seq);

		bitonic_compare(array, start, seq, dir);
		bitonic_merge(array, start, k, dir, size);
		bitonic_merge(array, start + k, k, dir, size);
	}
}

/**
 * bitonic_seq - Create bitonic sequences recursively
 * @array: Array to sort
 * @start: Starting index of sequence
 * @seq: Length of sequence
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 * @size: Total size of original array
 */
void bitonic_seq(int *array, size_t start, size_t seq, int dir, size_t size)
{
	size_t k = seq / 2;

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size,
				dir ? "UP" : "DOWN");
		print_array(array + start, seq);

		bitonic_seq(array, start, k, 1, size);
		bitonic_seq(array, start + k, k, 0, size);
		bitonic_merge(array, start, seq, dir, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2 || (size & (size - 1)) != 0)
		return;

	bitonic_seq(array, 0, size, 1, size);
}
