#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd1 = open("get_next_line.c", O_RDONLY);
	int fd2 = open("get_next_line.h", O_RDONLY);
	char *line;

	for (int i = 0; i < 50; i++)
	{
		line = get_next_line(fd1);
		printf("[%s]\n", line);
		free(line);
		// line = get_next_line(fd2);
		// printf("[%s]\n", line);
		// free(line);
	}
}
