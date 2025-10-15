#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	while (1)
	{
		printf("\"%s\"\n", get_next_line(0));
		printf("[%s]\n", get_next_line(fd));
	}
}
