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
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting, *output, max;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	counting = malloc(sizeof(int) * (max + 1));
	if (!counting)
		return;

	/* Initialize counting array */
	for (i = 0; i <= (size_t)max; i++)
		counting[i] = 0;

	/* Count occurrences */
	for (i = 0; i < size; i++)
		counting[array[i]]++;

	/* Calculate cumulative count */
	for (i = 1; i <= (size_t)max; i++)
		counting[i] += counting[i - 1];

	/* Print counting array */
	print_array(counting, max + 1);

	/* Create output array */
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(counting);
		return;
	}

	/* Build output array */
	for (i = size - 1; i < size; i--)
	{
		output[counting[array[i]] - 1] = array[i];
		counting[array[i]]--;
	}

	/* Copy back to original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(counting);
	free(output);
}
