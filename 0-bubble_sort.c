#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 *                  ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	/* Check for NULL array or size of 0 */
	if (array == NULL || size < 2)
		return;

	/* Iterate through array n-1 times */
	for (i = 0; i < size - 1; i++)
	{
		/* Each pass compares adjacent elements */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If current element is larger than next element, swap them */
			if (array[j] > array[j + 1])
			{
				/* Swap elements using temporary variable */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
