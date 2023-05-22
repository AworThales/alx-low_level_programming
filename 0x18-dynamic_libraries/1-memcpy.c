#include "main.h"
/**
 *_memcpy -   copy number bytes form adress "from" to the adress "to"
 *@dest: content is to be copied
 *@src: Source of the data to be copied
 *@n: bytes of the memory
 *Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int t;

	t = 0;
	while (t < n)  /*Delacring the WHILE*/
	{
		*(dest + t) = *(src + t); /*add 1 position dest and the src*/
		t++;

	} /*END WHILE*/


	return (dest);
}
