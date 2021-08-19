# Pipex

### The project
This project is an introduction to UNIX where we have to rebuild the pipe function of the terminal. Using `./pipex infile "cmd1" "cmd2" outfile` should be equal to the terminal use of : `< infile cmd1 | cmd2 > file2` where cmd are any shell command with its parameters (ex: `wc -l` or `ls -lA`)

### How to use it
Build the programme using the makefile:
  `make` or `make re`

  To clean the compilation files: `make clean` or `make fclean`

  Use the program in either way:
  `./pipex infile "cmd1" "cmd2" outfile`

   Check the program's leaks with:  valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all ./pipex infile "grep a1" "wc -w" outfile

### Resources on the topic
Understanding the pipe functionning in C and parent/child fork principle:
http://www.zeitoun.net/articles/communication-par-tuyau/start
  Understanding the execve function and environnement variables use:
https://man7.org/linux/man-pages/man2/execve.2.html
https://man7.org/linux/man-pages/man7/environ.7.html


