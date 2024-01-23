#include "sort.h"

/**
 * swap - utility function to swap to integers
 * @a: Store the value pointed to by a in t
 * @b: Assign the value pointed to by b to the memory location pointed to by a
 **/
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - it ensures that heap property is maintained at given index
 * @array: array to be sorted
 * @size: size of the array for printinging purposes
 * @idx: index at which to perform a heapify operatioon
 * @n: size of the heap
 * Return: null
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to be sorted
 * @size: size of the array
 * Return: null
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);

		maxHeapify(array, size, 0, i);
	}
}
