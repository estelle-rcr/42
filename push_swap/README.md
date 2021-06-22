# Push Swap

### The project
We create a program that sort efficiently a list of numbers (positive and negative) with a given set of authorized operations (such as invert two numbers, etc.). We must sort the numbers respecting a maximum number of operations according to the list given in input (max 12 operations for 5 numbers, less than 1500 for 100 numbers and less than 11500 for 500 numbers). For bigger list of numbers, the quick sort algorithm is used for better sorting performances.

### How to use it
Build the programme using the makefile:
  `make`

  Compile the bonus version:
  `make bonus`

  Use the program in either way:
  `./push_swap 0 2 7 -1 100 6`
  `ARG="0 2 7 -1 100 6"; ./push_swap $ARG`

   Check the program with the official checker from 42 (Linux distribution or Mac):
  `ARG="0 2 7 -1 1 6"; ./push_swap $ARG | ./checkers/checker_linux $ARG`
    `ARG="0 2 7 -1 100 6"; ./push_swap $ARG | ./checkers/checker_MAC $ARG`