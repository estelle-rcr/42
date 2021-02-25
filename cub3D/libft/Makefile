# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 15:30:27 by erecuero          #+#    #+#              #
#    Updated: 2021/02/17 16:08:02 by erecuero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_strstr.c\
		ft_itoa_base.c\
		ft_strcmp.c\
		ft_rev_int_tab.c\
		ft_sort_int_tab.c\
		ft_swap.c\
		ft_strcapitalize.c\
		ft_isspace.c\
		get_next_line.c\
		get_next_line_utils.c\

BONUS	= 	ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUS:.c=.o}

INCLUDE	= includes

NAME	= libft.a

CC	= clang
RM	= rm -f

CFLAGS=	-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS} ${BONUSOBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

bonus: ${OBJS} ${BONUSOBJS}
		ar rc ${NAME} ${OBJS} ${BONUSOBJS}
		ranlib ${NAME}

.PHONY: all clean fclean re bonus
