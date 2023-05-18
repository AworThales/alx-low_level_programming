#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate a key depending on the username for crackme5
 * @argc: number of arguments passed
 * @argv: arguments passed to main
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int t, d;
	size_t len, summ;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	for (t = 0, summ = 0; t < len; t++)
		summ += argv[1][t];
	p[1] = l[(summ ^ 79) & 63];
	for (t = 0, d = 1; t < len; t++)
		d *= argv[1][t];
	p[2] = l[(d ^ 85) & 63];
	for (d = argv[1][0], t = 0; t < len; t++)
		if ((char)d <= argv[1][t])
			d = argv[1][t];
	srand(d ^ 14);
	p[3] = l[rand() & 63];
	for (d = 0, t = 0; t < len; t++)
		d += argv[1][t] * argv[1][t];
	p[4] = l[(d ^ 239) & 63];
	for (d = 0, t = 0; (char)t < argv[1][0]; t++)
		d = rand();
	p[5] = l[(d ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
