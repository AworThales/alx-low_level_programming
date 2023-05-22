#include "main.h"
/**
 *_strncat - concatenates the two strings
 *@dest: A pointer to the character that will be changed
 *@src: A pointer to the character that will be changed
 *@n: value
 *Return: dest
 */

char *_strncat(char *dest, char *src, int n)

{
int t, d;

t = 0;
while (dest[t] != '\0')
{
t++;
}

d = 0;
while (d < n && src[d] != '\0')
{
dest[t] = src[d];
d++;
t++;
}

dest[t] = '\0';

return (dest);
}
