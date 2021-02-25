# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 11:22:26 by erecuero          #+#    #+#              #
#    Updated: 2021/02/17 16:08:23 by erecuero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cub3d_utils.c\
			ft_split_sep.c\
			handle_errors.c\
			main.c\
			minilib_utils.c\
			open_file.c\
			parser.c\
			parser_RTC.c\

INCLUDE	= cub3d.h

NAME	= cub3D.a

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
