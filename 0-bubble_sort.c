#include "sort.h"
/**
 * bubble_sort - it sorts an array of integers in an ascending order
 * @array: the pointer to the array to be sorted
 * @size: he size to the array to be sorted
 * Return: null or void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	temp = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1] && array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
