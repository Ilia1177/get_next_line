#ifndef GET_NEXTLINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strnchr(const char *s, int c, int n);
char	*ft_strdup(const char *s);
int		ft_strnlen(const char *str, int c);
char	*ft_strtrim(char const *s, char set);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
