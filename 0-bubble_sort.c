#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - function arranges the arrays in ascending using bubble sort
 * @array: the pointer to the arrays to be sorted
 * @size: The size of the array to be sorted
 * Return: null or void
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, index;
	int tmp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (index = 0; index < size - i - 1; index++)
		{
			if (array[index] > array[index + +1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, size);
			}
		}
	}
}
