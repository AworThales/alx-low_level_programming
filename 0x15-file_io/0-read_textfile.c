#include "main.h"

/**
 * read_textfile - reads a textfile and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t ne, wr;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	ne = read(fd, buf, letters);
	wr = write(STDOUT_FILENO, buf, ne);

	close(fd);

	free(buf);

	return (wr);
}
