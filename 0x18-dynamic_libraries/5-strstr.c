#include "main.h"

/**
 * _strstr - first occurrence of a substring needle in a string haystack
 * @haystack: main str to be examined
 * @needle: searched in haystack
 * Return: return 0
 **/

char  *_strstr(char *haystack, char *needle)
{
	char *str8, *str9; /*Declaring variables*/

	while (*haystack != '\0')
	{
		str8 = haystack; /*values*/
		str9 = needle;

		/*Star WHILE*/
		while (*haystack != '\0' && *str9 != '\0' && *haystack == *str9)
		{
			haystack++;
			str9++;
		}
		if (*str9 == '\0')
			return (str8);
		haystack = str8 + 1;
	}
	return (0);
}
