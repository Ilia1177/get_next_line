#include "get_next_line.h"
static char *get_characters(char *buff, char *paragraph, int fd);

char *get_next_line(int fd)
{
	static char	*paragraph;
	char		*characters;
	char		*line;
	char		*buffer;

	if (BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	characters = get_characters(buffer, paragraph, fd); //with a \n or \0 in it
	free(buffer);
	if (!characters)
	{
		if (!paragraph)
			return (0);
		line = paragraph;
		free(paragraph);
		paragraph = 0;
	}
	else
	{
		line = ft_strtrim(characters, '\n');
		if (*(characters + ft_strnlen(line, '\n')) == '\0')
		{
			free(paragraph);
			paragraph = 0;
		}
		else
			paragraph = ft_strtrim(characters + ft_strnlen(line, '\n'), '\n');
		free(characters);
		characters = 0;
	}
	return (line);




/*	char			*buff;
	char			*line;
	static char		*remain;
	char			*paragraph;
	int				line_len;

	if (BUFFER_SIZE <= 0)
		return (0);
	buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	paragraph = get_characters(buff, remain, fd);
	free(buff);
	if (!paragraph && !remain)
			return (0);
	



	if (paragraph)
	{
		line = ft_strtrim(paragraph, '\n');
		line_len = ft_strnlen(line, '\n');
		if (*(paragraph + line_len))
			remain = ft_strtrim(paragraph + line_len + 1, '\n');
		else
			remain = 0;
		free(paragraph);
	}
	else if (!paragraph && remain)
	{
		line = ft_strdup(remain);
		free(remain);
		remain = 0;
	}
	return (line);*/
}

static char *get_characters(char *buff, char *paragraph,  int fd)
{

	int		bytes_read;
	char	*characters;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
		if (bytes_read <= 0)
			return (0);
		if (!paragraph)  // 1ere initialisation of paragraph
			paragraph = ft_strdup(buff);
		else // free old paragraph and build new one (JOIN)
		{
			tmp = paragraph;
			paragraph = ft_strjoin(tmp, buff);
			free(tmp);
		}
		if (ft_strnchr(buff, '\n', BUFFER_SIZE)) //
			break;
	}
	return (paragraph);

/*	int			char_read;
	char		*characters;

	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, buff, BUFFER_SIZE);
		buff[char_read] = '\0';
		if (char_read <= 0)
			return (0);
		if (!paragraph)		// first initialisation of paragraph
			paragraph = ft_strdup(buff);
		else 				// join paragraph with buff
		{
			characters = paragraph;
			paragraph = ft_strjoin(characters, buff);
			free(characters);
		}
		if (ft_strnchr(buff, '\n', BUFFER_SIZE))
			break ;
	}*/
	return (paragraph);
}
