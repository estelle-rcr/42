# Philosophers

### The project
This project is about solving the classic Dining Philosophers problem. We can use threads (light parallel processes within a program) and mutex (mutual exclusion of a shared resource) to solve it. We create a unique program handling a certain number of philosophers who each sleep, eat, and sleep in parallel but cannot eat all at the same time as they share a limited number of forks. We have to avoid letting them starve to death.

### How to use it
Build the programme using the makefile:
  `make` or `make re`

  To clean the compilation files: `make clean` or `make fclean`

  Use the program:
  `./philo nb_of_philosophers time_to_die time_to_eat time_to_sleep [nb_of_times_each_philo_must_eat]`
   The time is in milliseconds and the last argument is optional as it defines an end to the program.

   Example: `./philo 4 410 200 200`
   Or: `./philo 4 410 200 200 10` (they must eat at least 10 times)

   Check the program's leaks with: `valgrind --trace-children=yes --leak-check=full ./philo 3 310 200 200`
   

### Resources on the topic
Documentation of the Dining philosopher problem:
https://en.wikipedia.org/wiki/Dining_philosophers_problem
https://sites.cs.ucsb.edu/~rich/class/cs170/notes/DiningPhil/index.html
  Tutorial on how to use thread and mutex in C:
https://www.tala-informatique.fr/wiki/index.php/C_pthread
  Tutorial on gettimeofday:
  https://linuxhint.com/gettimeofday_c_language/
