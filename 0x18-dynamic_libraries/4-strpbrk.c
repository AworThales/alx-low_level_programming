#include "main.h"

/**
 * _strpbrk - matches any character that is specified
 * @s: This is the C string to be scanned.
 * @accept:character in str1 that matches one of a characters in str2
 *Return: string s that matches any character specified in accept
 **/

char *_strpbrk(char *s, char *accept)
{
	int d;

	while (*s != '\0') /*Declaring WHILE*/
	{
		d = 0;
		while (accept[d] != '\0')  /*Evaluating *accept*/
		{
			if (*s == accept[d])
			{
				return (s);
			}

			d++; /*add d+1*/
		}

		s++; /*add s+1*/
	}
	return (0);

}
