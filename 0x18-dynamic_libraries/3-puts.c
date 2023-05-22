#include "main.h"
/**
 * _puts - pusts to the stdout
 * @str: params
 */

void _puts(char *str)
{
	int t = 0;

	while (str[t] != '\0')
	{
		_putchar(str[t]);
		t++;
	}

	_putchar('\n');
}
