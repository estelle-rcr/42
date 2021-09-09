/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 13:56:26 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/27 15:10:10 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	exit_error(int error_code, char *var)
{
	if (error_code == ERR_ARGS)
	{
		write(STDERR_FILENO, "parse error near ", 19);
		write(STDERR_FILENO, var, ft_strlen(var));
	}
	else if (error_code == ERR_INFILE)
	{
		write(STDERR_FILENO, var, ft_strlen(var));
		perror(" ");
	}
	else if (error_code == ERR_OUTFILE)
	{
		write(STDERR_FILENO, var, ft_strlen(var));
		perror(" ");
	}
	else if (error_code == ERR_CMD)
	{
		write(STDERR_FILENO, "command not found: ", 19);
		write(STDERR_FILENO, var, ft_strlen(var));
	}
	else
		exit_other_errors(error_code);
	exit(error_code);
}

void	exit_other_errors(int error_code)
{
	if (error_code == ERR_PIPE)
		perror("pipe failed");
	else if (error_code == ERR_FORK)
		perror("fork failed");
	else if (error_code == ERR_DUP)
		perror("dup2 failed");
	else if (error_code == ERR_JOIN)
		perror("path creation failed");
	else if (error_code == ERR_PATH)
		perror("cannot find path");
	else if (error_code == ERR_EXECVE)
		perror("execve failed");
	else
		perror(" ");
}

char	*ft_join_path(char const *s1, char c, char const *s2)
{
	char	*tab;
	int		size1;
	int		size2;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	tab = malloc((size1 + size2 + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	ft_memmove(tab, s1, size1);
	ft_memmove(tab + size1, &c, 1);
	ft_memmove(tab + size1 + 1, s2, size2);
	tab[size1 + size2 + 1] = '\0';
	return (tab);
}

char	**ft_free_dbl_tabs(char **tab1, char**tab2)
{
	int	i;

	i = -1;
	while (tab1 && tab1[++i])
		free(tab1[i]);
	free(tab1);
	i = -1;
	while (tab2 && tab2[++i])
		free(tab2[i]);
	free(tab2);
	return (0);
}

void	ft_free_all_exit(char **cmd_args, char **cmd_paths, char *cmd,
							int code_error)
{
	ft_free_dbl_tabs(cmd_args, cmd_paths);
	free(cmd);
	exit_error(code_error, NULL);
}
