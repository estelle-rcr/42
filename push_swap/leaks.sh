make && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$1 $2 2> leak_$1.log
