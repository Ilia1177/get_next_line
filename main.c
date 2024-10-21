#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
//	fd = 0;
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strnlen(line, '\n'));
		write(1, "\n", 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

	
