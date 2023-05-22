#include "main.h"
/**
 *_strcmp - compares the two strings
 *@s1: A pointer to the character that will be changed
 *@s2: A pointer to the character that will also be changed/updated/modified
 *Return: dest
 */

int _strcmp(char *s1, char *s2)

{

char *str_initial = s1;
char *str_final = s2;


while (*str_initial != '\0' && *str_final != '\0' && *str_initial == *str_final)
{
str_initial++;
str_final++;
}

return (*str_initial - *str_final);
}

