#!/bin/bash

RED="\033[91m"
GREEN="\033[92m"
YELLOW="\033[93m"
BLUE="\033[94m"
PURPLE="\033[95m"
CYAN="\033[96m"
WHITE="\033[97m"

make
mkdir leak_logs
nb=$(ls maps | wc -l)
i=1

while [ "$i" -le "$nb" ]; do
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D maps/invalid_map_$i.cub 2> leak_logs/leak_$i.log #&
	test=$(cat leak_logs/leak_$i.log | grep lost)
	if [ ! -z "$test" ];
	then
		echo -ne $RED
		echo -n "$i	---->	leaks :"
		echo -ne $WHITE
		echo -e "\033[0;31m x	\033[0m"
	else
		echo -ne $GREEN
		echo -n "$i	---->	leaks :"
		echo -ne $WHITE
		echo -e "\033[0;32m \xE2\x9C\x94	\033[0m"
	fi
    # sleep 2
	# ps -aux | grep -ie "cub3D" | grep -v 'grep' | awk '{print $2}' | xargs kill -9
    i=$(( $i + 1 ))
done