/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:43:12 by npolack           #+#    #+#             */
/*   Updated: 2024/10/24 11:04:26 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnlen(const char *str, int c)
{
	char	*start;

	start = (char *)str;
	while (*str && *str != c)
		str++;
	return (str - start);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		tlen;
	int		i;

	if (!s1 || !s2)
		return (0);
	tlen = ft_strnlen(s1, 0);
	tlen += ft_strnlen(s2, 0);
	dest = (char *)malloc((tlen + 1) * sizeof (char));
	if (!dest)
		return (0);
	i = 0;
	while (i < ft_strnlen(s1, 0))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (i < tlen)
	{
		*(dest + i) = *(s2 + i - ft_strnlen(s1, 0));
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;
	int		i;

	s_len = ft_strnlen(s, 0);
	dest = 0;
	dest = (char *)malloc((s_len + 1) * sizeof (char));
	if (!dest)
		return (0);
	i = 0;
	while (i < s_len)
	{
		*(dest + i) = *(s + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		dlen;

	if (!s)
		return (0);
	if ((s + ft_strnlen(s, 0)) > (s + start))
	{
		dlen = ft_strnlen(s + start, 0);
		if ((size_t)dlen > len)
			dlen = len;
	}
	else
		return (0);
	dest = 0;
	dest = (char *)malloc((dlen + 1) * sizeof (char));
	if (!dest)
		return (0);
	i = -1;
	while (++i < dlen && s[i + start] != '\0')
		dest[i] = s[start + i];
	dest[i] = '\0';
	return (dest);
}
