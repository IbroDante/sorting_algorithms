#include "sort.h"

/**
 * merge_subarrays - Merge two subarrays of an array.
 * @array: An array of integers to sort.
 * @buffer: A buffer to store the sorted subarrays.
 * @front: The index of the first element of the first subarray.
 * @mid: The index of the last element of the first subarray.
 * @back: The index of the last element of the second subarray.
 *
 * Description: This function merges two sorted subarrays of the array into a
 * single sorted array.
 */
void merge_subarrays(int *array, int *buffer, size_t front, size_t mid, size_t back)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + front, mid - front);
	printf("[right]: ");
	print_array(array + mid, back - mid);

	for (i = front, j = mid, k = 0; i < mid && j < back; k++)
	{
		if (array[i] <= array[j])
			buffer[k] = array[i++];
		else
			buffer[k] = array[j++];
	}

	while (i < mid)
		buffer[k++] = array[i++];

	while (j < back)
		buffer[k++] = array[j++];

	for (i = front, k = 0; i < back; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @array: An array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: The index of the first element of the subarray.
 * @back: The index of the last element of the subarray.
 *
 * Description: This function sorts a subarray of the array using the merge sort
 * algorithm.
 */
void merge_sort_recursive(int *array, int *buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = (front + back) / 2;
		merge_sort_recursive(array, buffer, front, mid);
		merge_sort_recursive(array, buffer, mid, back);
		merge_subarrays(array, buffer, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order using the merge sort
 *              algorithm.
 * @array: An array of integers to sort.
 * @size: The number of elements in the array.
 *
 * Description: This function sorts an array of integers using the merge sort
 * algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(size * sizeof(int));
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
