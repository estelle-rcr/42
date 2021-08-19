/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:06:42 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/17 15:39:39 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include "errors.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef int	t_pid;

int		main(int ac, char **av, char **envp);
void	ft_pipex(int infile, int outfile, char **av, char **envp);
int		handle_child_two(int outfile, char **av, char **envp, int *end);
int		handle_child_one(int infile, char **av, char **envp, int *end);
void	exec_child_proc(char *cmd_av, char **envp);

int		exit_error(int error_code, char *var);

char	*ft_join_path(char const *s1, char c, char const *s2);

#endif
