NAME = philo

SRCS =	main.c\
		init.c\
		philo.c\
		utils.c\
		jobs.c\
		print.c\
		ft_atoi.c\
		ft_atol.c\
		ft_isdigit.c\

OBJS =${addprefix srcs/,${SRCS:.c=.o}}

INCLUDES = includes

CC = clang

CFLAGS = -Wall -Werror -Wextra -g

LIB_THREAD = -lpthread

#MEM = -fsanitize=address

#THREAD = -fsanitize=thread

RM = rm -rf

.c.o:
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${MEM} ${THREAD} ${LIB_THREAD} -o ${NAME} ${OBJS} 

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} 

re: 		fclean all

.PHONY:		all clean fclean re
