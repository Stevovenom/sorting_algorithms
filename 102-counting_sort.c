#include "sort.h"

/**
 * _calloc - this is a calloc function in C
 * @nmemb: number of elements
 * @size: bit size of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		s[i] = '\0';

	return (s);
}

/**
 * counting_sort - its a function that implements the counting ort agorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: null
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0, *counter = NULL, *temp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];
	counter = _calloc(maximum + 1, sizeof(int));
	temp = _calloc(size + 1, sizeof(int));

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (index = 1; index <= maximum; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximum + 1);

	for (i = 0; i < size; ++i)
	{
		temp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(temp);
	free(counter);

}
