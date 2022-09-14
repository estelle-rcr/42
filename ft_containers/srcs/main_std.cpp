/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_std.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:16:33 by erecuero          #+#    #+#             */
/*   Updated: 2022/09/06 12:53:38 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stack>
#include <map>
#include <set>

#define STD	std
#include "tests_vector.cpp"
#include "tests_stack.cpp"
#include "tests_map.cpp"
#include "tests_set.cpp"
#include "main42.cpp"

#define NC 			"\e[0m"
#define CYN 		"\e[0;36m"
#define NEW 		"\e[0;33m"
#define GRN 		"\e[0;32m"
#define REDB 		"\e[41m"

int main()	{
	tests_vector();
	tests_stack();
	tests_map();
	tests_set();

	/* Uncomment the following for tests from the 42 main (will take longer to execute): */
	// main42(1000);
	
	return (0);
}

