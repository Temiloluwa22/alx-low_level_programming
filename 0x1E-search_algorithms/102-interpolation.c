#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using Interpolation search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: The first index where the value is located, or -1 if not found.
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	size_t low = 0, high = size - 1;

	while (low <= high && value >= array[low] && value <= array[high])
	{
		if (low == high)
		{
			if (array[low] == value)
				return (low);
			return (-1);
		}

		size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

		if (array[pos] == value)
		{
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
			return (pos);
		}
		else if (array[pos] < value)
		{
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
			low = pos + 1;
		}
		else
		{
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
			high = pos - 1;
		}
	}

	printf("Value checked array[%lu] is out of range\n", low);
	return (-1);
}

