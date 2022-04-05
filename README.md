# My student projects @42 Paris

### 1st project: Libft
The project aims at building our own lib with some mandatory and bonus functions in order to re-use them in latter projects.

  Functions:
memset, bzero, memcpy, memccpy, memmove, memchr, memcmp, memcmp, strlen, isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower, strchr, strrchr, strncmp, strlcpy, strlcat, strnstr, atoi, calloc, strdup, substr, strjoin, strtrim, split, itoa, strmapi, putchar_fd, putstr_fd, putendl_fd, putnbr_fd

### 2nd project: Get_next_line
This project asks to build functions to extract a line in any file. It can be re-used anywhere to get as many lines as needed from a file using a pointer. It returns 1 if a line has been read, 0 when reaching the end of file (EOF) and -1 when an error has occurred.

### 3rd project: ft_printf
We have to rebuild the essentials functionnalities of printf in order to re-use it in latter project. It can print any of the following specifiers: char, string, pointer, decimal, integer, unsigned integer, hexadecimal, capitalized hexadecimal and %. It integrates the following flags, width and precision : -0*.

### 4th project: ft_server
The ft_server project aims at creating a Docker container running with the LEMP stack (Linux, Nginx, MySQL, PHP) to host a Wordpress website, a mySQL database and a phpMyAdmin interface. It encompasses a self-signed SSL certificate using openSSL and an on-off switch for the index (through an ENV variable and through a script).

### 5th project: cub3D
We create a small 3D game inspired from Wolfenstein, a 90's game played in first-person view. We first make a parser to ensure the input file provided by the user is correct and that all the required data is provided in the right format. Then, we use the minilibX to display the game in 2D and then in 3D using the raycasting method.
I added many bonuses (a HUD, fog and reliefs, points and victory, object pick-up, life, keys, a display/hide map, look up and down, textures on floor and ceiling...). I also added two small scripts in shell to compile and check leaks with valgrind.

### 6th project: push swap
The aim of this project is to discover sorting algorithms, basic order and complexity notions, and specifically the sorting of small vs big sets of numbers.
We use a set of mandatory operations and two stacks to sort a list of numbers given as an input of the program. We must be efficient enough to stay under the recommended number of operations according to the input list given. We are finally benchmarked on a list of 100 and 500 random numbers.

### 7th project: pipex
This project is an introduction to the UNIX world and to the next project Minishell. We have to rebuild the pipe function of the terminal so that our program should be equal to the terminal use of : `< infile cmd1 | cmd2 > outfile`. In the bonus part, I handle multiple commands and pipes.

### 8th project: philosophers
This project is about solving the classic Dining Philosophers problem which is about resources sharing. We use threads (light parallel processes within a program) and mutex (mutual exclusion of a shared resource) to solve it.

### 9th project: minishell
In team of 2, we created a 'mini' version of Bash (norm posix) which is a shell (software that interprets and executes the various commands that we type in the terminal). We implemented a lexer, a parser, and an interpreter to handle complex commands (multi pipes, multi redirections, appends and heredocs, etc.)

### 10th project: CPP pool
The CPP pool makes us discover the C plus plus language and all its specificities in 9 modules: allocation, operator overloads, polymorphism, inheritances, abstract class & interfaces, exceptions, casts, templates, containers.

### 11th project: Inception
This project aims at creating a structure of Docker containers for each services of a website (Wordpress, Nginx, MariaDB).

### 12th project: Ft_containers
Soon

That's all folks!
