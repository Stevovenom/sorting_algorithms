#include "sort.h"

/**
 * _calloc - this is a calloc function in C
 * @nmemb: the nukber of elements
 * @size: bit size of each element
 * Return: pointer to memory allocated
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
 * merge - uses merge algorithm to arrange elments in ascending order
 * @arr: The array to be sorted
 * @tmp: temporary place holder for an array in merge sort
 * @start: teh index of the first element
 * @mid: the iindex of the element in the middle
 * @end: the index of the last element
 * Return: null
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;

	int left, right, i = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;

	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}

	while (left < size_left)
		arr[i] = array_left[left], left++, i++;

	while (right < size_right)
		arr[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 * mergesort - the function uses merge algorithm to arrange elements
 * @array: array of integers
 * @tmp: temporary place holder for an element in the merge
 * @start: fisrt element position
 * @end: last element position
 * Return: void
 */
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}
/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @size: size of the list
 * @array: array of integers
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = _calloc(size, sizeof(int));
	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
