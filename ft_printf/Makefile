# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 21:29:43 by erecuero          #+#    #+#              #
#    Updated: 2021/01/04 21:30:33 by erecuero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c\

INCLUDE	= printf.h

NAME	= libftprintf.a

CC	= clang

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror

LIB	= libft/libft.a
OBJS	= ${SRCS:.c=.o}


all : $(NAME)

$(NAME) : $(OBJS)
		$(MAKE) bonus -C ./libft
		cp $(LIB) $(NAME)
		ar rcs $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
