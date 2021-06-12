/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:23:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 13:57:36 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 31

# endif

char	*ft_strfind(const char *s, int c);
char	*ft_joinstr(char *s1, char *s2);
void	helper_gnl(char *buf, char *line, char *str);
int		get_next_line(int fd, char **line);

#endif
