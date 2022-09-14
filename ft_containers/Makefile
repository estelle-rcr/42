NAME = containers

FTNAMESPACE = ft

FTSRCS =	main_ft.cpp\

FTOBJS = ${addprefix srcs/,${FTSRCS:.cpp=.o}}

STDNAMESPACE = std

STDSRCS =	main_std.cpp\

STDOBJS = ${addprefix srcs/,${STDSRCS:.cpp=.o}}

INCL = includes

CXX = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

#FSANITIZE = -ggdb -fsanitize=address

#VALGRIND = -g3

.cpp.o:
		${CXX} ${CPPFLAGS} -I${INCL} -c $< -o ${<:.cpp=.o}

all:	${FTNAMESPACE}_${NAME} ${STDNAMESPACE}_${NAME}

${FTNAMESPACE}_${NAME}:	${FTOBJS}
			${CXX} ${CPPFLAGS} ${VALGRIND} ${FSANITIZE} ${FTOBJS} -o ${FTNAMESPACE}_${NAME}

${STDNAMESPACE}_${NAME}:	${STDOBJS}
			${CXX} ${CPPFLAGS} ${VALGRIND} ${FSANITIZE} ${STDOBJS} -o ${STDNAMESPACE}_${NAME}

clean:
			${RM} ${FTOBJS} ${STDOBJS}

fclean:		clean
			${RM} ${STDNAMESPACE}_${NAME} ${FTNAMESPACE}_${NAME}
			${RM} ft_tests std_tests

re: 		fclean all

.PHONY:		all clean fclean re
