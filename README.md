# My student projects @42 Paris

### 1st project: Libft
The project aims at building our own lib with some mandatory and bonus functions in order to re-use them in latter projects.
  
  Functions:  
memset, bzero, memcpy, memccpy, memmove, memchr, memcmp, memcmp, strlen, isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower, strchr, strrchr, strncmp, strlcpy, strlcat, strnstr, atoi, calloc, strdup, substr, strjoin, strtrim, split, itoa, strmapi, putchar_fd, putstr_fd, putendl_fd, putnbr_fd


### 2nd project: Get_next_line
This project asks to build functions to extract a line in any file. It can be re-used anywhere to get as many lines as needed from a file using a pointer. It returns 1 if a line has been read, 0 when reaching the end of file (EOF) and -1 when an error has occurred.


### 3rd project: ft_printf
We have to rebuild the essentials functionnalities of printf in order to re-use it in latter project. It can print any of the following specifiers: char, string, pointer, decimal, integer, unsigned integer, hexadecimal, capitalized hexadecimal and %. It integrates the following flags, width and precision : -0*.

### 4th project: cub3D
We create a small 3D game inspired from Wolfenstein, a 90's game played in first-person view. We first make a parser to ensure the input file provided by the user is correct and that all the required data is provided in the right format. Then, we use the minilibX to display the game in 2D and then in 3D using the raycasting method.  
I added many bonus: a HUD, fog and reliefs, points and victory, object pick-up, life, keys, jumps and crouch, textures on floor and ceiling...  
I added two small scripts in shell to compile and check leaks with valgrind. The first script is used as follow: './leaks.sh cub3D maps.cub' and check the program with one map in input, the result is in a log file. The second is used as follow: './test_invalid_maps.sh cub3D maps/' and check multiple invalid map files and output the OK/KO from valgrind tests on the terminal and the log files for each map files in a dedicated directory.
  
### 5th project: ft_server
The ft_server project aims at creating a Docker image running with LEMP stack (Linux, Nginx, MySQL, PHP) to host a Wordpress website and its database. It encompasses a self-signed SSL certificate and a on-off switch for the index.
  
    
That's all folks!
