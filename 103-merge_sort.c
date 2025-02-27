#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted array
 * @array: Original array containing subarrays to merge
 * @left: Starting index of left subarray
 * @mid: Ending index of left subarray
 * @right: Ending index of right subarray
 * @work: Working array for merging
 */
void merge(int *array, size_t left, size_t mid, size_t right, int *work)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			work[k++] = array[i++];
		else
			work[k++] = array[j++];
	}

	while (i < mid)
		work[k++] = array[i++];
	while (j < right)
		work[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = work[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively splits and merges array
 * @array: Array to sort
 * @left: Starting index
 * @right: Ending index
 * @work: Working array for merging
 */
void merge_sort_recursive(int *array, size_t left, size_t right, int *work)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, left, mid, work);
	merge_sort_recursive(array, mid, right, work);
	merge(array, left, mid, right, work);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *work;

	if (array == NULL || size < 2)
		return;

	work = malloc(sizeof(int) * size);
	if (work == NULL)
		return;

	merge_sort_recursive(array, 0, size, work);

	free(work);
}
