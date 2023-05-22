#include "main.h"

/**
 * _atoi - converts the string to an integer.
 * @s: params
 * Return: something
 */
int _atoi(char *s)
{
	unsigned int start = 0, size = 0, d = 0, g = 1, m = 1, i;

	while (*(s + start) != '\0')
	{
		if (size > 0 && (*(s + start) < '0' || *(s + start) > '9'))
			break;

		if (*(s + start) == '-')
			g *= -1;

		if ((*(s + start) >= '0') && (*(s + start) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		start++;
	}

	for (i = start - size; i < start; i++)
	{
		d = d + ((*(s + i) - 48) * m);
		m /= 10;
	}
	return (d * g);
}
