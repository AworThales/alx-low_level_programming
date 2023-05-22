#include "main.h"

/**
 * _strchr - Locates the character in thr string
 * @s: String
 * @c: Character to search
 * Return: Pointer to a first occurrence of a character c in the string s
 **/

char *_strchr(char *s, char c)
{

	while (*s != '\0') /*Declaring WHILE*/
	{
		if (*s == c) /*if s ==  c*/
		{
			return (s); /*return s*/
		}

		++s;
	}

	if (*s == c)
	{
		return (s);

	}


	return (0);/* values null*/
}
