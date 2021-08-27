NAME = pipex

SRCS =	main.c\
		ft_pipex.c\
		utils.c\

OBJS =${addprefix srcs/,${SRCS:.c=.o}}

BONUS_OBJS =${addprefix bonus/,${SRCS:.c=.o}}

INCLUDES = includes

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

LIB = libft/libft.a

.c.o:
		${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
			make -C libft
			${CC} ${CFLAGS} -L libft -o ${NAME} ${OBJS} ${LIB}

bonus:		${BONUS_OBJS}
			make -C libft
			${CC} ${CFLAGS} -L libft -o ${NAME}_bonus ${BONUS_OBJS} ${LIB}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}
			make clean -C libft

fclean:		clean
			${RM} ${NAME} ${NAME}_bonus ${LIB}

re: 		fclean all

.PHONY:		all clean fclean re
