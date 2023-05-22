#include "main.h"

/**
 * _strcpy - copies string
 * @dest: poiter
 * @src: poiter
 * Return: char
 */

char *_strcpy(char *dest, char *src)
{
	int t;

	for (t = 0; *(src + t) != '\0'; t++)
	{
		dest[t] = *(src + t);
	}
	dest[t] = '\0';

	return (dest);
}
