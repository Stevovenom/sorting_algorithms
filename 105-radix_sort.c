#include "sort.h"

/**
* getMax - It finds and returs teh maximum value in an array 'arr' and size 'n'
* @arr: array to be sorted
* @n: size of the array
* Return: maximum value in an array
*/
int getMax(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
* countSort - It performs a counting sort based on a digit position
* @arr: array to be sorted
* @n: size of the array to be sorted
* @exp: exp is 10^i which represents the position of the digit to sorted
* @output: stores the sorted elements temporarily
* Return: null
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
}

/**
* radix_sort - The main function that performs the main RADIX algorithm
* @array: array to be sorted
* @size: size of the array
* Return: null
*/
void radix_sort(int *array, size_t size)
{
	int exp, maximum = 0;
	int *output = '\0';

	if (array == NULL || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
