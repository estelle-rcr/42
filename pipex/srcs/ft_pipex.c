/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:57:01 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/19 17:17:22 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
			{
				ft_free_tab(cmd_args);
				ft_free_tab(cmd_paths);
				free(cmd);
				exit_error(ERR_EXECVE, NULL);
			}
		}
		free(cmd);
	}
	ft_free_tab(cmd_args);
	ft_free_tab(cmd_paths);
	exit_error(ERR_CMD, cmd_av);
}

int	handle_child_one(int infile, char **av, char **envp, int *end)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		exit_error(ERR_DUP, NULL);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		exit_error(ERR_DUP, NULL);
	close(end[0]);
	close(infile);
	exec_child_proc(av[2], envp);
	exit(EXIT_FAILURE);
}

int	handle_child_two(int outfile, char **av, char **envp, int *end)
{
	if (dup2(outfile, STDOUT_FILENO) < 0)
		exit_error(ERR_DUP, NULL);
	if (dup2(end[0], STDIN_FILENO) < 0)
		exit_error(ERR_DUP, NULL);
	close(end[1]);
	close(outfile);
	exec_child_proc(av[3], envp);
	exit(EXIT_FAILURE);
}

void	ft_pipex(int infile, int outfile, char **av, char **envp)
{
	int		end[2];
	int		status;
	t_pid	child1;
	t_pid	child2;

	status = 0;
	if (pipe(end) == -1)
		exit_error(ERR_PIPE, NULL);
	child1 = fork();
	if (child1 < 0)
		exit_error(ERR_FORK, NULL);
	if (child1 == 0)
		handle_child_one(infile, av, envp, end);
	child2 = fork();
	if (child2 < 0)
		exit_error(ERR_FORK, NULL);
	if (child2 == 0)
		handle_child_two(outfile, av, envp, end);
	close(end[0]);
	close(end[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}
