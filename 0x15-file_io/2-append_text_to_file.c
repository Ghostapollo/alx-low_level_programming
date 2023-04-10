#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int j, a, w;

	if (filename == NULL)
		return (-1);

	j = open(filename, O_WRONLY | O_APPEND);
	if (j == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(j);
		return (1);
	}

	for (a = 0; text_content[a]; a++)
		;

	w = write(j, text_content, a);
	if (w == -1)
	{
		close(j);
		return (-1);
	}
	close(j);
	return (1);
}
