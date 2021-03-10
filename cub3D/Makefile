# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 11:22:26 by erecuero          #+#    #+#              #
#    Updated: 2021/03/10 19:35:49 by erecuero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/cub3d_utils.c\
			srcs/floodfill_check.c\
			srcs/ft_split_sep.c\
			srcs/handle_errors.c\
			srcs/init_mlx.c\
			srcs/minilib_utils.c\
			srcs/open_file.c\
			srcs/parser.c\
			srcs/parser_check_map.c\
			srcs/parser_cpy_map.c\
			srcs/parser_params.c\

NAME = cub3D

MAIN = ./srcs/main.c

OBJ_MAIN = ${MAIN:.c=.o}

PATH_SRCS = ./

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS = ${_SRCS:.c=.o}

LINK = ar rc

CC = clang

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

PATH_HEADER = ./

.c.o:
			${CC} ${FLAGS} -I${PATH_HEADER} -c $< -o ${<:.c=.o}

MYLIB = mylib.a

PATH_MLX_LINUX = ./minilibx-linux/

MLX_LINUX = ./minilibx-linux/libmlx_Linux.a

all:        ${NAME}

${NAME}:    ${MV} ${OBJ_MAIN} ${OBJS}
			${LINK} ${MYLIB} ${OBJS}
			ranlib ${MYLIB}
			make -C ${PATH_MLX_LINUX}
			${CC} ${FLAGS} -o3 ${OBJ_MAIN} ${MYLIB} ${MLX_LINUX} -lm -lbsd -lX11 -lXext -o ${NAME} libft/libft.a

clean:
			${RM} ${OBJ_MAIN} ${OBJS}
			make clean -C ${PATH_MLX_LINUX}

fclean:     clean
			${RM} ${NAME} ${MYLIB} ${MLX_LINUX}

re:         fclean all

.PHONY:     all clean fclean re
