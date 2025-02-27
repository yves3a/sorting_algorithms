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
 * create_counting_array - Creates and fills the counting array
 * @array: Original array
 * @size: Size of original array
 * @max: Maximum value in original array
 * Return: Pointer to counting array
 */
int *create_counting_array(int *array, size_t size, int max)
{
	int *counting = malloc(sizeof(int) * (max + 1));
	size_t i;

	if (!counting)
		return (NULL);

	for (i = 0; i <= (size_t)max; i++)
		counting[i] = 0;

	for (i = 0; i < size; i++)
		counting[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		counting[i] += counting[i - 1];

	print_array(counting, max + 1);
	return (counting);
}

/**
 * build_output_array - Builds the sorted output array
 * @array: Original array
 * @size: Size of array
 * @counting: Counting array
 * @output: Output array
 */
void build_output_array(int *array, size_t size, int *counting, int *output)
{
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		output[counting[array[i]] - 1] = array[i];
		counting[array[i]]--;
	}
}

/**
 * counting_sort - Sorts an array using counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *counting, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	counting = create_counting_array(array, size, max);
	if (!counting)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(counting);
		return;
	}

	build_output_array(array, size, counting, output);

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(counting);
	free(output);
}
