#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a heap
 * @array: The array to be sorted
 * @size: Size of the array
 * @root: Root index of the heap
 * @max: Maximum index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < max && array[left] > array[largest])
		largest = left;

	if (right < max && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_ints(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	/* Extract elements from heap one by one */
	for (i = size - 1; i > 0; i--)
	{
		swap_ints(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
