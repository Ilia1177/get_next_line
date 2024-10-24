#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd1;
	int fd2;
	char *line;

	(void)ac;
	(void)av;
	fd1 = open("test.txt", O_RDONLY);
	fd2= open("test2.txt", O_RDONLY);

/*	line = get_next_line(fd1);
	write(1, line, ft_strnlen(line, 0));
	free(line);
	line = get_next_line(fd2);
	write(1, line, ft_strnlen(line, 0));
	free(line);
	line = get_next_line(fd1);
	write(1, line, ft_strnlen(line, 0));
	free(line);
	line = get_next_line(fd2);
	write(1, line, ft_strnlen(line, 0));
	free(line);
	close(fd1);
	close(fd2);*/

//	while (line)dd
//	while (line)dd
//	while (line)dd
	line = get_next_line(fd1);
	while (line)
	{
		write(1, line, ft_strnlen(line, 0));
		free(line);
		line = get_next_line(fd2);
		write(1, line, ft_strnlen(line, 0));
		free(line);
		line = get_next_line(fd1);
	}
	free(line);
	close(fd1);
	close(fd2);
}
	
