#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd1;
	int fd2;
	char *line1;
	char *line2;

	(void)ac;
	(void)av;
	fd1 = open("test.txt", O_RDONLY);
	fd2= open("test3.txt", O_RDONLY);

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
	line1 = get_next_line(fd1);
	while (line1 || line2)
	{
		if (line1)
		{
			write(1, line1, ft_strnlen(line1, 0));
			free(line1);
			line1 = get_next_line(fd1);
		}
		if (line2)
		{
			write(1, line2, ft_strnlen(line2, 0));
			free(line2);
			line2 = get_next_line(fd2);
		}
	}
	free(line1);
	free(line2);
	close(fd1);
	close(fd2);
}
	
