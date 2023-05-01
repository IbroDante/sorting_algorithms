#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 *
 * Return: void
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: Array of integers to sort
 * @size: Size of the array
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 *
 * Return: Partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap_ints(&array[i], &array[j]);
            if (i != j)
                print_array(array, size);
        }
    }

    swap_ints(&array[i + 1], &array[high]);
    if (i + 1 != high)
        print_array(array, size);

    return (i + 1);
}

/**
 * quicksort - Sorts an array of integers in ascending order
 * @array: Array of integers to sort
 * @size: Size of the array
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 *
 * Return: void
 */
void quicksort(int *array, size_t size, int low, int high)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, size, low, high);
        quicksort(array, size, low, pivot - 1);
        quicksort(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: Array of integers to sort
 * @size: Size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, size, 0, size - 1);
}
