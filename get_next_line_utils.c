#include "get_next_line.h"

int	ft_strnlen(const char *str, int c)
{
	char *start;

	start = (char *)str;
	while(*str && *str != c)
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

char	*ft_strtrim(char const *s, char set)
{
	char	*dest;
	int		len;
	int		i;

	if (s == 0)
		return (0);
	len = ft_strnlen(s, set);
	if (len <= 0)
	{	
		dest = (char*)malloc(1 * sizeof (char));
		dest = '\0';
		return (dest);
	}
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while (++i <= len)
		*(dest + i) = *(s + i);
//	*(dest + len) = '\0';
	return (dest);
}
