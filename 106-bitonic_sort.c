#include "sort.h"
#include <stdio.h>

#define UP 1
#define DOWN 0

/**
 * swap_elements - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers
 * @array: Array to sort
 * @size: Size of the array
 * @start: Starting index of the sequence
 * @seq: Size of sequence to sort
 * @flow: Direction to sort (1 for UP, 0 for DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t start,
		size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_elements(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence
 * @array: Array to sort
 * @size: Size of the array
 * @start: Starting index of the block
 * @seq: Size of the block
 * @flow: Direction to sort (1 for UP, 0 for DOWN)
 */
void bitonic_seq(int *array, size_t size, size_t start,
		size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
