/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:43:08 by npolack           #+#    #+#             */
/*   Updated: 2024/10/28 15:37:03 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_paragraph(char *paragraph, char *current_line);
static char	*get_characters(char *buffer, char *paragraph, int fd);

char	*get_next_line(int fd)
{
	static char		*paragraph;
	char			*buffer;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	paragraph = get_characters(buffer, paragraph, fd);
	free(buffer);
	if (!paragraph)
		return (0);
	if (ft_strchr(paragraph, '\n'))
	{
		line = ft_substr(paragraph, 0, ft_strnlen(paragraph, '\n') + 1);
		paragraph = make_paragraph(paragraph, line);
	}
	else
	{
		line = ft_strdup(paragraph);
		free(paragraph);
		paragraph = 0;
	}
	return (line);
}

static char	*make_paragraph(char *paragraph, char *current_line)
{
	char	*tmp;
	ssize_t	para_len;
	ssize_t	line_len;
	ssize_t	new_plen;

	line_len = ft_strnlen(current_line, 0);
	para_len = ft_strnlen(paragraph, 0);
	new_plen = para_len - line_len;
	tmp = paragraph;
	paragraph = ft_substr(tmp, line_len, new_plen);
	free(tmp);
	return (paragraph);
}

static char	*get_characters(char *buffer, char *paragraph, int fd)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (paragraph);
		buffer[bytes_read] = '\0';
		if (!paragraph)
			paragraph = ft_strdup(buffer);
		else
		{
			tmp = paragraph;
			paragraph = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (paragraph);
}
