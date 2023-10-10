#include "search_algos.h"

/**
 * _binary_search - a function that searches for a value in a
 * sorted array of integers using the Exponential search algorithm
 * @array: pointer to the first element of the array to search.
 * @left: starting index of the [sub]array to search.
 * @right: ending index of the [sub]array to search.
 * @value: value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 * if not, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t n;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (n = left; n < right; n++)
			printf("%d, ", array[n]);
		printf("%d\n", array[n]);

		n = left + (right - left) / 2;
		if (array[n] == value)
			return (n);
		if (array[n] > value)
			right = n - 1;
		else
			left = n + 1;
	}

	return (-1);
}

/**
 * exponential_search - a function that searches for a value in a
 * sorted array of integers using the Exponential search algorithm
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 * if not, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t n = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (n = 1; n < size && array[n] <= value; n = n * 2)
			printf("Value checked array[%ld] = [%d]\n", n, array[n]);
	}

	right = n < size ? n : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", n / 2, right);
	return (_binary_search(array, n / 2, right, value));
}
