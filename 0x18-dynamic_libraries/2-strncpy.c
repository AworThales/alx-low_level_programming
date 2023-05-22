#include "main.h"
/**
 *_strncpy - copies a string
 *@dest: A pointer to the character that will be changed
 *@src: A pointer to the character that will be changed
 *@n: value
 *Return: dest
 */

char *_strncpy(char *dest, char *src, int n)

{
int t;

t = 0;
while (t < n && src[t] != '\0')
{
dest[t] = src[t];
t++;
}

while (t < n)
{
dest[t] = '\0';
t++;
}

return (dest);

}
