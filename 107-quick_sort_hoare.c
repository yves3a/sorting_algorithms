#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partition array using Hoare scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Array size
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
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
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * hoare_sort - Recursive function to sort array
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Array size
 */
void hoare_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high, size);

		hoare_sort(array, low, pivot, size);
		hoare_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sort array using Quick sort with Hoare partition
 * @array: Array to sort
 * @size: Size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}
