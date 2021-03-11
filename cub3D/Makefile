NAME = cub3D

SRCS =	cub3d_utils.c\
		floodfill_check.c\
		ft_split_sep.c\
		handle_errors.c\
		init_mlx.c\
		main.c\
		minilib_utils.c\
		open_file.c\
		parser.c\
		parser_check_map.c\
		parser_cpy_map.c\
		parser_RTC.c\

PATH_SRCS = srcs/

OBJS = ${addprefix ${PATH_SRCS},${SRCS:.c=.o}}

CC = clang

CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft

LIBFT_LIB = libft/libft.a

MLX_DIR = minilibx-linux

MLX_LIB_LINUX = minilibx-linux/libmlx_Linux.a

INC_DIR = includes

HEADS = -I${LIBFT_DIR}/includes -I${MLX_DIR} -I${INC_DIR}

LFLAGS = -L ${LIBFT_DIR} -L ${MLX_DIR}

LIBS = -lm -lbsd -lXext -lX11 -lft

RM = rm -rf

.c.o:
			${CC} ${CFLAGS} ${HEADS} -g -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):    ${OBJS}
			make -C ${LIBFT_DIR}
			make -C ${MLX_DIR}
			${CC} ${CFLAGS} ${LFLAGS} ${LIBS} ${OBJS} -o ${NAME} libft/libft.a

clean:
			${RM} ${OBJS}
			make clean -C ${MLX_DIR}
			make clean -C ${LIBFT_DIR}

fclean:     clean
			${RM} ${NAME} ${MLX_LIB_LINUX} ${LIBFT_LIB}

re:         fclean all

.PHONY:     all clean fclean re
