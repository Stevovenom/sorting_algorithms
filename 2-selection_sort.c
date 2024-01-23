#include "sort.h"

/**
 * selection_sort - implements Selection Sort algorithm to sort an
 * array of integers in ascending order
 * @size: a pointer to the first element of the array to be sorted
 * @array: the number of elements in the array.
 * Return: null
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[temp] > array[j])
			{
				temp = j;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[temp];
		array[temp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
