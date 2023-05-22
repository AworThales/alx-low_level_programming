#include "main.h"
/**
 *_memset -   fills memory with the constant byte
 *@s: pointer block of the memory to fill
 *@b: value to set
 *@n: bytes of memory
 *Return: dest
 */

char *_memset(char *s, char b, unsigned int n)

{
	unsigned int t;

	/*Delacring FOR*/
	for (t = 0; t < n; t++)
	{
		*(s + t) = b; /*add 1 position s*/

	} /*END FOR*/

	return (s);
}
