#include "sort.h"

/**
 * swap - swaps teh position of two elements in an array
 * @array: array of elements to be swapped
 * @item1: indices of the elements to be swapped
 * @item2:second index of the elements to be swapped
 * Return: null
*/
void swap(int *array, int item1, int item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 * @size: size of the array
 * @array: list with numbers
 * Return: Null
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		print_array(array, size);
		gap /= 3;
	}
}
