NAME = cub3D

SRCS =	cub3d_utils.c\
		errors.c\
		events.c\
		exit_mlx.c\
		ft_get_file.c\
		ft_split_sep.c\
		init_mlx.c\
		main.c\
		minilib_utils.c\
		open_file.c\
		parser_check_map.c\
		parser_cpy_map.c\
		parser_params.c\
		parser.c\
		raycasting_init.c\
		raycasting_player.c\
		raycasting_sprite.c\
		raycasting_textures.c\
		raycasting.c\
		save.c\

BONUS =	cub3d_utils.c\
		errors.c\
		events.c\
		exit_mlx.c\
		ft_get_file.c\
		ft_split_sep.c\
		init_mlx.c\
		main.c\
		minilib_utils.c\
		open_file.c\
		parser_check_map.c\
		parser_cpy_map.c\
		parser_params.c\
		parser.c\
		raycasting_init.c\
		raycasting_player.c\
		raycasting_sprite.c\
		raycasting_textures.c\
		raycasting.c\
		save.c\
		floodfill_check.c\
		parser_map_tabs.c\
		events_bonus.c\
		display_map.c\
		raycasting_text_cf.c\
		raycasting_add_sprites.c\
		display_assets.c\
		handle_interaction.c\

PATH_SRCS = srcs/

OBJS = ${addprefix ${PATH_SRCS},${SRCS:.c=.o}}

PATH_BONUS = bonus/

BONUSOBJS = ${addprefix ${PATH_BONUS},${BONUS:.c=.o}}

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3

LIBFT_DIR = libft

LIBFT_LIB = libft/libft.a

MLX_DIR = minilibx-linux

MLX_LIB_LINUX = minilibx-linux/libmlx_Linux.a

INC_DIR = includes

INC_BONUS_DIR = includes-bonus

HEADS = -I${LIBFT_DIR}/includes -I${MLX_DIR} -I${INC_DIR} -I${INC_BONUS_DIR}

LFLAGS = -L ${LIBFT_DIR} -L ${MLX_DIR}

LIBS = -lm -lbsd -lXext -lX11 -lft

RM = rm -rf

.c.o:
			${CC} ${CFLAGS} ${HEADS} -g -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):    ${OBJS}
			make -C ${LIBFT_DIR}
			make -C ${MLX_DIR}
			${CC} ${CFLAGS} ${LFLAGS} ${LIBS} ${OBJS} -o ${NAME} ${LIBFT_LIB} ${MLX_LIB_LINUX}

clean:
			${RM} ${OBJS} ${BONUSOBJS}
			make clean -C ${MLX_DIR}
			make clean -C ${LIBFT_DIR}

fclean:     clean
			${RM} ${NAME} ${NAME}_bonus ${MLX_LIB_LINUX} ${LIBFT_LIB}

re:         fclean all

bonus:		${BONUSOBJS}
			make -C ${LIBFT_DIR}
			make -C ${MLX_DIR}
			${CC} ${CFLAGS} ${LFLAGS} ${LIBS} ${BONUSOBJS} -o ${NAME}_bonus ${LIBFT_LIB} ${MLX_LIB_LINUX}

.PHONY:     all clean fclean re bonus
