#include "sort.h"

/**
 * swap - the function swaps the position of two elements in an array
 * @array: array containing the elements in an array
 * @item1: The index of the first element to be swapped
 * @item2: The index of the second element to be swapped
 * Return: null
**/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - function implement Lomuto partition scheme for Quick Sort
 * @array: the array to be partitioned
 * @first: The index of the first element of the partition.
 * @last: The index of the last element of the partition.
 * @size: the size of the array
 * Return: return the position of the last element sorted
 */

int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * qs - qucksort algorithm implementation
 * @array: array to be sorted
 * @first: first array element
 * @last: last array element
 * @size: array size
 * Return: null
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * quick_sort - prepare the terrain to quicksort algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: null
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
