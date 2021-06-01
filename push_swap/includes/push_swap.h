/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:00:59 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/01 16:47:52 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>							// printf

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_ops
{
	int				op;
	struct s_ops	*next;
}				t_ops;

typedef struct	s_vars
{
	t_stack		*start_a;
	t_stack		*start_b;
	t_ops		*ops;
	int			*int_list;			// not useful?
	char		**ops_list;
	int			nb_input;
	int			len_a;
	int			len_b;
}				t_vars;

int				main(int ac, char **av);
int				parse_args(t_vars *vars, int ac, char **av);
int				parse_list(t_vars *vars, char **av);
t_vars			*init_vars(void);
t_stack			*add_new_stack(t_stack *first, int nb);
int				ft_atoi_extended(const char *str, t_vars *vars);
int				exit_free(t_vars *vars);

#endif
