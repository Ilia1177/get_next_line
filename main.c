#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
//	fd = 0;
	while (line)
	{
		write(1, line, ft_strnlen(line, '\n'));
		write(1, "\n", 1);
		free(line);
		line = get_next_line(fd);
	}
}

	
