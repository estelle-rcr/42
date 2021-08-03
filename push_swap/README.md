# Push Swap

### The project
We create a program that sort efficiently a list of numbers (positive and negative) with a given set of authorized operations (such as invert two numbers, etc.). We must sort the numbers respecting a maximum number of operations according to the list given in input (max 12 operations for 5 numbers, less than 1500 for 100 numbers and less than 11500 for 500 numbers). For bigger list of numbers, the algorithm is improved by chunking the list of numbers for better performances.

### How to use it
Build the programme using the makefile:
  `make` or `make re`

  To clean the compilation files: `make clean` or `make fclean`

  Use the program in either way:
  `./push_swap 0 2 7 -1 100 6`
  `ARG="0 2 7 -1 100 6"; ./push_swap $ARG`

   Check the program with the official checkers from 42 (Linux distribution or Mac):
  `ARG="0 2 7 -1 1 6"; ./push_swap $ARG | ./checkers/checker_linux $ARG`
    `ARG="0 2 7 -1 100 6"; ./push_swap $ARG | ./checkers/checker_MAC $ARG`

  Generate random numbers to test the algo on a list of 100 and 500 numbers:
  For 100 numbers: `./push_swap $(shuf -i 0-10000 -n 100)`
  For 500 numbers: `./push_swap $(shuf -i 0-1000000 -n 500)`

  Or: `shuf -i 0-1000 -n 100 > test_files/rand100 && ./push_swap $(cat test_files/rand100) | ./checkers/checker_Mac $(cat test_files/rand100)`

  Or (for 42's Macs): `ARG=`ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checkers/checker_Mac $ARG`

  You can also use the bash script for valgrind test as such:
  `ARG="0 2 7 -1 100 6"; ./leaks.sh push_swap $ARG`
