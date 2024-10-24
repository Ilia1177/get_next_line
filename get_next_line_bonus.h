/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:28:49 by npolack           #+#    #+#             */
/*   Updated: 2024/10/24 17:06:30 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
///////////////////////////// BONUS ////////////////////////////////////////////
//	gnl.c
char	*get_next_line(int fd);
//	gnl.utils.c
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_strnlen(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
#endif
