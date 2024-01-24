#include "sort.h"
/**
 * swap - Its a utility function used to swap two elements in an array
 * @array: array to be sorted
 * @item1: array element representing index 1
 * @item2: array element representing index 2
 * Return: null
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - it implements the Hoare partition scheme for QuickSort
 * @array: array to be sorted
 * @first: first array element
 * @last: last array element
 * @size: size array
 * Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * qs -  a recursive function that implements the QuickSort algorithm using
 * Hoare partition scheme
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
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - the entry point of the QuickSort algorithm using
 * the Hoare partition scheme
 * @array: array to be sorted
 * @size: array size
 * Return: null
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
