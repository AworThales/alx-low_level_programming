#include "main.h"
#include <stdio.h>
/**
 *_puts - prints a string
 * @str: string to print
 * Description: prints a string
 * Return: Always 0 (Success)
 */
void _puts(char *str)
{
int i = 0;
while (str[i])
{
_putchar(str[i]);
i++;
}
_putchar('\n');
}
