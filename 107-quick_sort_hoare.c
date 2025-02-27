#include "sort.h"

/**
 * swap_elements - Swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Partitions the array using Hoare's scheme
 * @array: Array to partition
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partition
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		if (i < j)
		{
			swap_elements(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * quick_sort_recursive - Recursively sorts array using quicksort
 * @array: Array to sort
 * @low: Starting index of partition to sort
 * @high: Ending index of partition to sort
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using the Quick sort algorithm
 * with Hoare partition scheme
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
