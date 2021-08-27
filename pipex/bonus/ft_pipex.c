/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:57:01 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/27 16:36:46 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths_envp(char **envp)
{
	int		i;
	char	**cmd_paths;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			cmd_paths = ft_split(envp[i] + 5, ':');
			if (cmd_paths)
				return (cmd_paths);
		}
	}
	return (NULL);
}

void	exec_child_proc(char *cmd_av, char **envp)
{
	char	**cmd_paths;
	char	**cmd_args;
	int		i;
	char	*cmd;

	cmd_paths = get_paths_envp(envp);
	if (!cmd_paths)
		exit_error(ERR_PATH, NULL);
	cmd_args = ft_split(cmd_av, ' ');
	i = -1;
	while (cmd_paths[++i])
	{
		cmd = ft_join_path(cmd_paths[i], '/', cmd_args[0]);
		if (!cmd)
			exit_error(ERR_JOIN, NULL);
		if (access(cmd, X_OK) == 0 && open(cmd, O_RDONLY) > 0)
		{
			if (execve(cmd, cmd_args, envp) == -1)
				ft_free_all_exit(cmd_args, cmd_paths, cmd, ERR_EXECVE);
		}
		free(cmd);
	}
	ft_free_dbl_tabs(cmd_args, cmd_paths);
	exit_error(ERR_CMD, cmd_av);
}

void	handle_children(char *av, char **envp)
{
	t_pid	parent;
	int		pipe_end[2];
	int		status;

	status = 0;
	if (pipe(pipe_end) == -1)
		exit_error(ERR_PIPE, NULL);
	parent = fork();
	if (parent < 0)
		exit_error(ERR_FORK, NULL);
	if (!parent)
	{
		close(pipe_end[0]);
		if (dup2(pipe_end[1], STDOUT_FILENO) < 0)
			exit_error(ERR_DUP, NULL);
		exec_child_proc(av, envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(parent, &status, 0);
		close(pipe_end[1]);
		if (dup2(pipe_end[0], STDIN_FILENO) < 0)
			exit_error(ERR_DUP, NULL);
	}
}

void	ft_pipex(int infile, int outfile, int ac, char **av, char **envp)
{
	int	i;

	if (dup2(infile, STDIN_FILENO) < 0)
		exit_error(ERR_DUP, NULL);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		exit_error(ERR_DUP, NULL);
	i = 2;
	handle_children(av[i], envp);
	while (++i < ac - 2)
		handle_children(av[i], envp);
	exec_child_proc(av[ac - 2], envp);
	exit(EXIT_FAILURE);
}
