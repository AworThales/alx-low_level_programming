#include "main.h"
/**
 *_strcat - concatenate two strings
 *@dest: A pointer to the character that will be changed
 *@src: A pointer to the character that will also be changed
 *Return: dest
 */

char *_strcat(char *dest, char *src)
{
int t, d;

t = 0;
while (dest[t] != '\0')
{
t++;
}

d = 0;
while (src[d] != '\0')
{
dest[t] = src[d];
d++;
t++;
}
dest[t] = '\0';

return (dest);
}
