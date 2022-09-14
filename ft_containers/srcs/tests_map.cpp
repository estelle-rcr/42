#include "pair.hpp"
#include "map.hpp"
#include <map>
#include <utility>
#include <iostream>

#define NC "\e[0m"
#define CYN "\e[0;36m"
#define YEL "\e[0;33m"
#define GRN "\e[0;32m"
#define RED "\e[41m"

////
//// HOW TO USE:
//// Change the TESTED_TYPE variable to test different types: int, char, long long, etc.
////

#ifndef TESTED_TYPE1
#define TESTED_TYPE1	int
#endif

#ifndef TESTED_TYPE2
#define TESTED_TYPE2	int
#endif

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

#define T1 int
#define T2 std::string

int tests_map(void)
{
		std::cout << RED << "\n>>> TESTS FOR MAP <<<" << NC << std::endl;

	{
		std::cout << YEL << "\n>> Default constructor: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 1);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> emptyMap;

		std::cout << GRN << "\n>> Empty map constructor OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insertion of int pairs test: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 1);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		pair = NAMESPACE::make_pair(3, 3);
		map.insert(pair);
		pair = NAMESPACE::make_pair(2, 22);
		map.insert(pair);
		pair = NAMESPACE::make_pair(4, 1);
		map.insert(pair);
		std::cout << GRN << "\n>> Insert 4 pairs OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insertion of int pairs test: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		for (int i = 0; i < 100000; i++) {
			pair = NAMESPACE::make_pair(i, i + 1);
			map.insert(pair);
		}
		std::cout << GRN << "\n>> Insert 100000 pairs OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator forward test: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 1);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 3);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 22);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 1);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 1);
		map.insert(pair8);
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Iterator forward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator backward test: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 1);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 3);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 22);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 1);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 1);
		map.insert(pair8);
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.end();
		it--;
		for (; it != map.begin(); --it)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Iterator backward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator reverse test: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 1);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 3);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 22);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 1);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 1);
		map.insert(pair8);
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::reverse_iterator it;
		for (it = map.rbegin(); it != map.rend(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Iterator reverse OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Iterator forward test: " << NC << std::endl;
		const NAMESPACE::pair<const int, int> pair(1, 1);
		NAMESPACE::map<const int, int> map;
		map.insert(pair);
		const NAMESPACE::pair<const int, int> pair3(3, 3);
		map.insert(pair3);
		const NAMESPACE::pair<const int, int> pair2(2, 22);
		map.insert(pair2);
		const NAMESPACE::pair<const int, int> pair4(4, 1);
		map.insert(pair4);
		const NAMESPACE::pair<const int, int> pair8(8, 1);
		map.insert(pair8);
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<const int, int>::const_iterator it;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->first<< std::endl;
		std::cout << GRN << "\n>> Const Iterator forward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Iterator reverse test: " << NC << std::endl;
		NAMESPACE::pair<const TESTED_TYPE1, TESTED_TYPE2> pair(1, 1);
		NAMESPACE::map<const TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 3);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 22);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 1);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 1);
		map.insert(pair8);
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<const TESTED_TYPE1, TESTED_TYPE2>::reverse_iterator it;
		for (it = map.rbegin(); it != map.rend(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Const Iterator reverse OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Range constructor: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 31);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 31);
		map.insert(pair8);

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2(map.begin(), map.end());
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map2.begin(); it != map2.end(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Range map constructor OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Copy constructor: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 31);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 31);
		map.insert(pair8);

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2(map);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map2.begin(); it != map2.end(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Copy constructor map OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Assign operator: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 31);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 31);
		map.insert(pair8);

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2 = map;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map2.begin(); it != map2.end(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n>> Assign operator OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Empty function: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 31);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 31);
		map.insert(pair8);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;

		std::cout << "Is map empty? " << map.empty() << " should be false" << std::endl;
		std::cout << "Is map2 empty? " << map2.empty() << " should be true" << std::endl;

		std::cout << GRN << "\n>> Empty OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Size function: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 31);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 31);
		map.insert(pair8);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;

		std::cout << "What is map size? " << map.size() << " - should be 5" << std::endl;
		std::cout << "What is map2 size? " << map2.size() << " - should be 0" << std::endl;

		std::cout << GRN << "\n>> Size OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Max Size function: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 31);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 31);
		map.insert(pair8);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;

		std::cout << map.max_size() << std::endl;
		std::cout << map2.max_size() << std::endl;

		std::cout << GRN << "\n>> Max Size OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Operator[] function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair8(8, 36);
		map.insert(pair8);

		std::cout << "Value at pos 3: " << map[3] << " should be 32" << std::endl;
		std::cout << "Value at pos 8: " << map[8] << " should be 31" << std::endl;
		std::cout << "Value at pos 7 (not existing): " << map[7] << std::endl;
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n>> Operator[] OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Operator[] with assignation function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map[3] = 32;
		map[2] = 11;
		map[1] = 33;
		map[8] = 11;
		map[8] = 11;

		std::cout << "Value at pos 3: " << map[3] << " should be 32" << std::endl;
		std::cout << "Value at pos 8: " << map[8] << " should be 11" << std::endl;
		std::cout << "Value at pos 7 (not existing): " << map[7] << std::endl;
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n>> Operator[] with assignation OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Operator[] with assignation function: " << NC << std::endl;
		NAMESPACE::map<char, std::string> map;
		map['a'] = "an element";
		map['b'] = "another element";
		map['c'] = map['b'];
		map['b'] = "old element";

		std::cout << "Value at pos a: " << map['a'] << " should be an element" << std::endl;
		std::cout << "Value at pos c: " << map['c'] << " should be another element" << std::endl;
		std::cout << "Value at pos d (not existing): " << map['d'] << std::endl;
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<char, std::string>::iterator it;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n>> Operator[] with assignation OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insert by value function: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		std::cout << "Return of first insert is " << (map.insert(pair)).second << std::endl;
		std::cout << "Return of re-insert is " << (map.insert(pair)).second << std::endl;
		map.insert(pair2);

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Insert by value OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insert by pos + value function: " << NC << std::endl;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		map.insert(pair);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		std::cout << "Return of first insert is at " << map.insert(it, pair2)->second << std::endl;
		std::cout << "Return of re-insert is at " << map.insert(it, pair2)->second << std::endl;

		for (it = map.begin(); it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Insert by pos OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insert by iterator range function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		map.insert(it, pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator ite = map.end();
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;

		map2.insert(map.begin(), ite);

		for (it = map2.begin(); it != map2.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Insert by iterator range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by key function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);

		std::cout << "Return of first erase is at " << map.erase(2) << std::endl;
		std::cout << "Return of re-erase is at " << map.erase(2) << std::endl;

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Erase by key range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by key function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);

		std::cout << "Return of first erase is at " << map.erase(2) << std::endl;
		std::cout << "Return of re-erase is at " << map.erase(2) << std::endl;

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Erase by key range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase tricky case: " << NC << std::endl;
		NAMESPACE::map<T1, T2> mp;
		mp[5] = "FFFFF";
		mp[8] = "II";
		mp[10] = "Hello";
		mp[11] = "Hi there";

		mp.erase(--(--(--mp.end())), mp.end());
		std::cout << std::endl << "PRINT MAP:" << std::endl;
		NAMESPACE::map<int, std::string>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << "Iterator value: " << (it)->first << std::endl;
		std::cout << GRN << "\n> Erase by tricky case OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by key function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);

		std::cout << "Return of first erase is at " << map.erase(2) << std::endl;
		std::cout << "Return of re-erase is at " << map.erase(2) << std::endl;

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Erase by key range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by key function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);

		std::cout << "Return of first erase is at " << map.erase(2) << std::endl;
		std::cout << "Return of re-erase is at " << map.erase(2) << std::endl;

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Erase by key range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by position (iterator) function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);

		map.erase(map.begin());

		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Erase by position (iterator) range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by iterator range function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);

		map.erase(map.begin(), map.end());


		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Erase by iterator range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Clear function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair5(5, 30);
		map.insert(pair5);

		map.clear();


		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Clear OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Swap function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair5(1, 8);
		map2.insert(pair5);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair6(2, 3);
		map2.insert(pair6);

		map.swap(map2);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		for (; it != map.end(); it++)
			std::cout << "Iterator value: " << (it)->second << std::endl;
		std::cout << GRN << "\n> Swap OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Key & Value comp functions: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.begin();
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator ite = map.end();
		ite--;
		std::cout << "Key comp: " << (map.key_comp())(it->first, ite->first) << std::endl;
		std::cout << "Value comp: " << (map.value_comp())(*it, pair4) << std::endl;
		std::cout << GRN << "\n> Key & Value comp OK " << NC << std::endl;
	}
	{
		NAMESPACE::map<char, float>	mp;

		mp['a'] = 2.3;
		mp['b'] = 1.4;
		mp['c'] = 0.3;
		mp['d'] = 4.2;
		static unsigned int i = 0;
		std::cout << "Max Size " << mp.max_size() << std::endl;
		NAMESPACE::map<char, float>::const_iterator it1;
		NAMESPACE::map<char, float>::const_iterator it2;
		for (it1 = mp.begin(); it1 != mp.end(); ++it1)
			for (it2 = mp.begin(); it2 != mp.end(); ++it2){
				bool res[2];

				std::cout << "\t-- [" << ++i << "] --" << std::endl;
				res[0] = mp.key_comp()(it1->first, it2->first);
				res[1] = mp.value_comp()(*it1, *it2);
				std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
				std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
			}
	}
	{
		std::cout << YEL << "\n>> Find by key function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it = map.find(3);
		std::cout << "Find pair3 [3 - 32]: [" << it->first << " - " <<  it->second << "]" << std::endl;
		std::cout << GRN << "\n> Find by key OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const find by key function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		const NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map1 = map;
		const NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::const_iterator it = map1.find(4);
		std::cout << "Find pair4 [4 - 30] in map1 (exists): [" << it->first << " - " <<  it->second << "]" << std::endl;
		std::cout << GRN << "\n> Const find by key OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Count function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		std::cout << "Count if pair [4 - 30] exists: " << map.count(4) << std::endl;
		std::cout << "Count if key 5 exists (it doesn't): " << map.count(5) << std::endl;
		std::cout << GRN << "\n> Count OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Lowerbound function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it1 = map.lower_bound(4);
		std::cout << "Lowerbound of pair [3 - 30] is: [" << it1->first << " - " <<  it1->second << "]" << std::endl;
		std::cout << GRN << "\n> Lowerbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Lowerbound function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		const NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map1 = map;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::const_iterator it1 = map1.lower_bound(4);
		std::cout << "Const Lowerbound of pair [3 - 30] is: [" << it1->first << " - " <<  it1->second << "]" << std::endl;
		std::cout << GRN << "\n> Const Lowerbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Upperbound function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator it1 = map.upper_bound(3);
		std::cout << "Upperbound of pair [3 - 30] is: [" << it1->first << " - " <<  it1->second << "]" << std::endl;
		std::cout << GRN << "\n> Upperbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Upperbound function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		const NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map1 = map;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::const_iterator it1 = map1.upper_bound(3);
		std::cout << "Const Upperbound of pair [3 - 30] is: [" << it1->first << " - " <<  it1->second << "]" << std::endl;
		std::cout << GRN << "\n> Const Upperbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Equal range function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		NAMESPACE::pair<NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator, NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::iterator> pairIts;
		pairIts = map.equal_range(3);
		std::cout << "Equal range of pair [3 - 30] is: [" << (pairIts.first)->first << " - " <<  (pairIts.second)->first << "]" << std::endl;
		pairIts = map.equal_range(5);
		std::cout << GRN << "\n> Equal range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Equal range function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map.insert(pair4);
		const NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map1 = map;
		NAMESPACE::pair<NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::const_iterator, NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2>::const_iterator> pairIts;
		pairIts = map1.equal_range(3);
		std::cout << "Const Equal range of pair [3 - 30] is: [" << (pairIts.first)->first << " - " <<  (pairIts.second)->first << "]" << std::endl;
		pairIts = map1.equal_range(5);
		std::cout << GRN << "\n> Const Equal range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Get Allocator function: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map.insert(pair);
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map2;
		std::cout << "Allocator test on max size map 1: " << map.get_allocator().max_size() << std::endl;
		std::cout << "Allocator test on max size map 2: " << map2.get_allocator().max_size() << std::endl;
		std::cout << GRN << "\n> Get Allocator range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << std::endl << ">> Test of operators for comparison: " << NC << std::endl;
		NAMESPACE::map<TESTED_TYPE1, TESTED_TYPE2> map1, map2, map3;
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair(1, 18);
		map1.insert(pair);
		map2.insert(pair);
		map3.insert(pair);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair2(2, 33);
		map1.insert(pair2);
		map2.insert(pair2);
		map3.insert(pair2);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair3(3, 32);
		map1.insert(pair3);
		map2.insert(pair3);
		map3.insert(pair3);
		NAMESPACE::pair<TESTED_TYPE1, TESTED_TYPE2> pair4(4, 30);
		map3.insert(pair4);
		std::cout << "map1 == map2 ? Result is = " << (map1 == map2) << std::endl;
		if ((map1 == map2) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "map2 == map3 ? Result is = " << (map2 == map3) << std::endl;
		if ((map2 == map3) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "map2 >= map3 ? Result is = " << (map2 >= map3) << std::endl;
		if ((map2 >= map3) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO"<< NC << std::endl;
		std::cout << "map2 > map3 ? Result is = " << (map2 > map3) << std::endl;
		if ((map2 > map3) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "map2 <= map3 ? Result is = " << (map2 <= map3) << std::endl;
		if ((map2 <= map3) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "map2 < map3 ? Result is = " << (map2 < map3) << std::endl;
		if ((map2 < map3) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "map2 != map3 ? Result is = " << (map2 != map3) << std::endl;
		if ((map2 != map3) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "map1 != map2 ? Result is = " << (map1 != map2) << std::endl;
		if ((map1 != map2) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
	}
	return 0;
}
