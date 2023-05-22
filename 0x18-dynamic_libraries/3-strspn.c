#include "main.h"

/**
 * _strspn - Locates the character in a string
 * @s: This is a main C string to be scanned.
 * @accept: This is a string containing the list of characters to match in s
 * Return: return start
 **/

unsigned int _strspn(char *s, char *accept)

{
	int t, d;
	int start = 0;
	char *str8, *str9;

	str8 = s;
	str9 = accept;

	t = 0;
	while (str8[t] != '\0') /*Declaring WHILE *s */
	{
		d = 0;
		while (str9[d] != '\0') /*Declaring WHILE *accept*/
		{
			if (str9[d] == str8[t]) /*Evaluate condition*/
			{
				start++; /*start number*/
				break;
			}

			d++;    /*add d+1*/
		}

		if (s[t] != accept[d]) /*If aren't equals*/
		{
			break;
		}

		t++; /*add x+1*/
	}

	return (start); /*return the value of start*/
}
