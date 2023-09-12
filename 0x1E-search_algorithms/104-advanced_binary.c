#include "search_algos.h"

/**
 * rec_search - searches for a value in an array of
 * integers using the Binary search algorithm
 *
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int rec_search(int *array, size_t size, int value)
{
	size_t halve = size / 2;
	size_t k;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (k = 0; k < size; k++)
		printf("%s %d", (k == 0) ? ":" : ",", array[k]);

	printf("\n");

	if (halve && size % 2 == 0)
		halve--;

	if (value == array[halve])
	{
		if (halve > 0)
			return (rec_search(array, halve + 1, value));
		return ((int)halve);
	}

	if (value < array[halve])
		return (rec_search(array, halve + 1, value));

	halve++;
	return (rec_search(array + halve, size - halve, value) + halve);
}

/**
 * advanced_binary - calls to rec_search to return
 * the index of the number
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
