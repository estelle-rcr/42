/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:09:07 by erecuero          #+#    #+#             */
/*   Updated: 2021/01/14 17:56:18 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# define HEX_C		"0123456789ABCDEF"
# define HEX_L		"0123456789abcdef"
# define DEC		"0123456789"

typedef struct		s_flaglist
{
	char	type;
	int		left_justified;
	int		zero_padded;
	int		width;
	int		precision;
	int		size;
}					t_flaglist;

int					ft_printf(const char *format, ...);
void				get_flags(t_flaglist *tmp, const char *format,
						int *i, va_list args);
int					print_regular(char c);
int					print_arg(t_flaglist *tmp, va_list args);
t_flaglist			new_flaglist(void);
int					is_flag(char c);
int					is_type(char c);
void				get_number(t_flaglist *tmp, char nb);
void				correct_values(t_flaglist *tmp);
int					fill_space(int i, char c);
char				*ft_joinstr(char *s1, char *s2);
void				ft_putnbr_long(int n);
int					print_char(int c, t_flaglist *tmp);
int					fill_ch(char c, t_flaglist *tmp);
int					print_str(char *s, t_flaglist *tmp);
void				correct_val_str(t_flaglist *tmp, int s_len);
int					fill_str(t_flaglist *tmp, char *s);
char				*handle_null(char *s);
int					print_ptr(void *ptr, t_flaglist *tmp);
int					fill_ptr(char *ptr);
int					print_int(int nb, t_flaglist *tmp);
int					fill_int(t_flaglist *tmp, int nb, int sign);
int					ft_len_nb(int n, int len_base_to);
int					handle_null_int(t_flaglist *tmp, int count);
void				correct_val_int(t_flaglist *tmp, int nb);
void				ft_putnbr_uns(unsigned int nb, char *base_to);
int					ft_len_unl(unsigned long n, int len_base_to);
void				ft_putnbl_base(unsigned long n, char *base_to);
int					print_u_int(unsigned int nb, t_flaglist *tmp);
int					fill_u_int(t_flaglist *tmp, unsigned int nb);
int					ft_len_un(unsigned int n, int len_base_to);
void				ft_putnbr_base(unsigned int n, char *base_to);
int					print_hex(unsigned int hex, t_flaglist *tmp);
int					fill_hex(t_flaglist *tmp, char *ar);

#endif
