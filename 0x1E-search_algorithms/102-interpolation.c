#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of
 * integers using the Interpolation search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, lower, higher;
	double k;

	if (array == NULL)
		return (-1);

	lower = 0;
	higher = size - 1;

	while (size)
	{
		k = (double)(higher - lower) / (array[higher] - array[lower]) * (value - array[lower]);
		pos = (size_t)(lower + k);
		printf("Value checked array[%d]", (int)pos);

		if (pos >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[pos]);
		}

		if (array[pos] == value)
			return ((int)pos);

		if (array[pos] < value)
			lower = pos + 1;
		else
			higher = pos - 1;

		if (lower == higher)
			break;
	}

	return (-1);
}
