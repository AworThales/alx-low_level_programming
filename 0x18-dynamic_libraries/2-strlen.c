#include "main.h"
/**
 * _strlen - string lenght
 * @s: params
 * Return: int
 */

int _strlen(char *s)
{
	int start = 0;

	while (s[start] != '\0')
	{
		start++;
	}

	return (start);
}
