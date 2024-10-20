#include "get_next_line.h"
static char *get_characters(char *buff, char *paragraph, int fd);

char *get_next_line(int fd)
{
	char			*buff;
	char			*line;
	char			*remain;
	static char		*paragraph;
	int				line_len;

	buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	paragraph = get_characters(buff, paragraph, fd);
	free(buff);
	if (!paragraph)
		return (0);
	line = ft_strtrim(paragraph, '\n');
	line_len = ft_strnlen(line, '\n');
	remain = ft_strtrim(paragraph + line_len + 1, '\n');
	paragraph = remain;
	return (line);
}

static char *get_characters(char *buff, char *paragraph,  int fd)
{
	int			char_read;
	char		*characters;

	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, buff, BUFFER_SIZE);
		buff[char_read] = '\0';
		if (char_read <= 0)
			return (0);	
		if (!paragraph)
			paragraph = ft_strdup(buff);
		else
		{
			characters = paragraph;
			paragraph = ft_strjoin(characters, buff);
			free(characters);
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (paragraph);
}
