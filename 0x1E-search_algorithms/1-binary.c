#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 *                 using the Binary search algorithm
 * @array: sorted array of integers
 * @size: size of the array
 * @value: value to be searched
 *
 * Return: index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	if (size <= 1)
		return (0);

	return (binary_recursion(array, 0, size - 1, value));
}

/**
 * binary_recursion - executes the Binary search algorithm with recursion
 * @array: sorted array of integers
 * @first: first index of the sub-array
 * @last: last index of the sub_array
 * @value: value to be searched
 *
 * Return: index where value is located
 */
int binary_recursion(int *array, size_t first, size_t last, int value)
{
	size_t pivot, index;

	if (first > last)
		return (-1);

	pivot = ((last - first) / 2) + first;

	print_array(array, first, last);

	if (array[pivot] == value)
		return (pivot);
	else if (array[pivot] > value)
		index = binary_recursion(array, first, pivot - 1, value);
	else if (array[pivot] < value)
		index = binary_recursion(array, pivot + 1, last, value);

	return (index);
}

/**
 * print_array - prints an array or sub-array in a Bianry search algorithm
 * @array: sorted array or sub-array of integers
 * @first: first index of the sub-array
 * @last: last index of the sub-array
 *
 * Return: void
 */
void print_array(int *array, size_t first, size_t last)
{
	size_t i;

	printf("Searching in array:");
	for (i = first; i <= last; i++)
	{
		printf(" %d", array[i]);
		if (i < last)
			printf(",");
	}
	printf("\n");
}
