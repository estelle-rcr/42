NAME = push_swap

SRCS =	main.c\
		exit.c\
		init.c\
		parser.c\
		ops_push.c\
		ops_reverse.c\
		ops_rotate.c\
		ops_swap.c\
		helpers.c\
		helpers_stacks.c\
		sort.c\
		sort_many.c\

OBJS =${addprefix srcs/,${SRCS:.c=.o}}

INCLUDES = includes

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

LIBS = libft/libft.a

.c.o:
		${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
		make -C libft
		${CC} ${CFLAGS} -L libft -o ${NAME} ${OBJS} ${LIBS}

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:	clean
		${RM} ${NAME} ${LIBS}

re: fclean all

.PHONY:	all clean fclean re
