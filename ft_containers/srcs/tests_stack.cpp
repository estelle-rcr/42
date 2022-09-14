#include "stack.hpp"
#include <iostream>
#include <stack>
#include <vector>

#define NC "\e[0m"
#define CYN "\e[0;36m"
#define NEW "\e[0;33m"
#define GRN "\e[0;32m"
#define REDB "\e[41m"


////
//// HOW TO USE:
//// Change the TESTED_TYPE variable to test different types: int, char, long long, etc.
////

#ifndef TESTED_TYPE
#define TESTED_TYPE	char
#endif

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

void	tests_stack(void) {
	std::cout << REDB << "\n>>> TESTS FOR STACK <<<" << NC << std::endl;

	// CONSTRUCTORS
	std::cout << GRN << std::endl << ">> Create 4 different stacks of tested type: " << NC << std::endl;
 	NAMESPACE::vector<TESTED_TYPE> myvector (2,20);        // vector with 2 elements

	std::cout << "Creation of an uninizialised stack of tested type (using ft::vector as default container for ft and deque for std) " << std::endl;
	NAMESPACE::stack<TESTED_TYPE> first;                    // empty stack
	std::cout << "size of first: " << first.size() << std::endl << std::endl;

	std::cout << "Creation of a stack initialised with a deque of 3 tested types" << std::endl;
	NAMESPACE::stack<TESTED_TYPE, std::deque<TESTED_TYPE> > second;         // stack initialized to copy of deque
	std::cout << "size of second: " << second.size() << std::endl;

	std::cout << "Creation of a stack as a vector container uninitialized" << std::endl;
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > third;  // empty stack using vector
	std::cout << "size of third: " << third.size() << std::endl << std::endl;


	std::cout << "Creation of a stack as a std::vector container uninitialized" << std::endl;
	NAMESPACE::stack<TESTED_TYPE, std::vector<TESTED_TYPE> > fourth;  // empty stack using vector
	std::cout << "size of fifth: " << fourth.size() << std::endl << std::endl;


	// EMPTY
	std::cout << GRN << std::endl << ">> Tests on empty: " << NC << std::endl;
	std::cout << "Test empty on stack 1: " << first.empty() << std::endl;
	std::cout << "Test empty on stack 2: " << second.empty() << std::endl;
	std::cout << "Test empty on stack 3: " << third.empty() << std::endl;
	std::cout << "Test empty on stack 4: " << fourth.empty() << std::endl;


	// TEST ON PUSH, EMPTY, TOP & POP FOR DEFAULT CONSTRUCTOR
	std::cout << GRN << std::endl << ">> Test of push, empty, top & pop with default stack created: " << NC << std::endl;
	NAMESPACE::stack<TESTED_TYPE> mystack;
	int sum (0);
	std::cout << "Test of pushing 10 values (adding) " << std::endl;
	for (int i=1;i<=10;i++) mystack.push(i);
	std::cout << "Counting the sum of all elements contained in myvector until it's empty (pop on elements)" << std::endl;
	while (!mystack.empty())
	{
		sum += mystack.top();
		std::cout << "top element of mystack: " << mystack.top() << std::endl;
		mystack.pop();
		std::cout << "size of mystack after pop: " << mystack.size() << std::endl;
	}
	std::cout << std::endl << "The sum is: " << sum << std::endl;

	std::cout << GRN << std::endl << ">> Test of push, empty, top & pop with a stack created from a copy of a vector: " << NC << std::endl;
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > mystack3 (myvector);
	sum = 0;
	std::cout << "Test of pushing 10 values (adding) " << std::endl;
	for (int i=1; i<=1000; i++) mystack3.push(i);
	std::cout << "Counting the sum of all elements contained in myvector until it's empty (pop on elements)" << std::endl;
	while (!mystack3.empty())
	{
		sum += mystack3.top();
		mystack3.pop();
	}
	std::cout << "size of mystack3 after all pop: " << mystack3.size() << std::endl;
	std::cout << std::endl << "The sum is: " << sum << std::endl;

	// TEST COMPARATORS
	std::cout << GRN << std::endl << ">> Test of operators for comparison: " << NC << std::endl;
	NAMESPACE::stack<TESTED_TYPE, NAMESPACE::vector<TESTED_TYPE> > mystack4, mystack5, mystack6;
	for (int i=1; i<=100; i++) mystack4.push(i + 1);
	for (int i=1; i<=100; i++) mystack5.push(i + 1);
	for (int i=1; i<=200; i++) mystack6.push(i + 1);
	std::cout << "mystack4 == mystack5 ? Result is = " << (mystack4 == mystack5) << std::endl;
	if ((mystack4 == mystack5) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack5 == mystack6 ? Result is = " << (mystack5 == mystack6) << std::endl;
	if ((mystack5 == mystack6) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack5 >= mystack6 ? Result is = " << (mystack5 >= mystack6) << std::endl;
	if ((mystack5 >= mystack6) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack5 > mystack6 ? Result is = " << (mystack5 > mystack6) << std::endl;
	if ((mystack5 > mystack6) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack5 <= mystack6 ? Result is = " << (mystack5 <= mystack6) << std::endl;
	if ((mystack5 <= mystack6) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack5 < mystack6 ? Result is = " << (mystack5 < mystack6) << std::endl;
	if ((mystack5 < mystack6) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack5 != mystack6 ? Result is = " << (mystack5 != mystack6) << std::endl;
	if ((mystack5 != mystack6) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "mystack4 != mystack5 ? Result is = " << (mystack4 != mystack5) << std::endl;
	if ((mystack4 != mystack5) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;

}
