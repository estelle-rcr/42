/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:56:25 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/19 17:18:27 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_error(int error_code, char *var)
{
	if (error_code == ERR_ARGS)
		printf("parse error near '%s'", var);
	else if (error_code == ERR_INFILE)
		printf("permission denied: %s\n", var);
	else if (error_code == ERR_OUTFILE)
		printf("permission denied: %s\n", var);
	else if (error_code == ERR_PIPE)
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
	else if (error_code == ERR_CMD)
		perror("command not found");
	exit(error_code);
}
