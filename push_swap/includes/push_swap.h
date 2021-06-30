/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:00:59 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/30 11:45:59 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>							// printf

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_ops
{
	int				nb;
	struct s_ops	*next;
}				t_ops;

typedef struct s_vars
{
	t_stack		*start_a;
	t_stack		*start_b;
	t_ops		*ops;
	char		**ops_list;
	int			nb_input;
	int			len_a;
	int			len_b;
	int			max;
	int			pos_max;
	int			min;
	int			pos_min;
}				t_vars;

typedef enum	e_errors
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_errors;

int				main(int ac, char **av);

t_vars			*init_vars(void);
t_stack			*add_new_item(t_stack *first, int nb);
t_ops			*add_new_op(t_ops *first, int nb);

int				ft_atoi_extended(const char *str, t_vars *vars, int *j);
int				parse_args(t_vars *vars, char **av);
int				check_input(t_vars *vars);

int				count_stack_nb(t_stack *stack);
int				is_sorted(t_stack *stack);
void			find_max(t_vars *vars);
void			find_min(t_vars *vars);
void			do_op(t_vars *vars, int(*f)(t_vars*), int op);

int				exit_free_error(t_vars *vars);
int				exit_free(t_vars *vars);

void			sort_input(t_vars *vars);
void			sort_few(t_vars *vars);
void			sort_three(t_vars *vars);
void			sort_many(t_vars *vars);

void			sort_some(t_vars *vars);

int				f_sa(t_vars *vars);
int				f_sb(t_vars *vars);
int 			f_ss(t_vars *vars);

int				f_pa(t_vars *vars);
int				f_pb(t_vars *vars);

int				f_ra(t_vars *vars);
int				f_rb(t_vars *vars);
int				f_rr(t_vars *vars);

int				f_rra(t_vars *vars);
int				f_rrb(t_vars *vars);
int				f_rrr(t_vars *vars);

void			print_stacks(t_vars *vars);
void			print_ops(t_vars *vars);



#endif
