#include "sort.h"

/**
 * get_max - Gets the maximum value in an array
 * @array: Array to find max value in
 * @size: Size of the array
 * Return: Maximum value in array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Modified counting sort for radix sort
 * @array: Array to sort
 * @size: Size of array
 * @exp: Current exponent (position) to sort by
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output;
	int counting[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	/* Store count of occurrences in counting[] */
	for (i = 0; i < size; i++)
		counting[(array[i] / exp) % 10]++;

	/* Change counting[i] to contain actual position */
	for (i = 1; i < 10; i++)
		counting[i] += counting[i - 1];

	/* Build the output array */
	for (i = size - 1; i < size; i--)
	{
		output[counting[(array[i] / exp) % 10] - 1] = array[i];
		counting[(array[i] / exp) % 10]--;
	}

	/* Copy the output array to array[] */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the Radix sort algorithm (LSD)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	/* Do counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
