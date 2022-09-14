#include "set.hpp"
#include "pair.hpp"
#include <set>
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
#define TESTED_TYPE2	char
#endif

#ifndef TESTED_TYPE3
#define TESTED_TYPE3	std::string
#endif

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif


int tests_set(void)
{
		std::cout << RED << "\n>>> TESTS FOR SET <<<" << NC << std::endl;

	{
		std::cout << YEL << "\n>> Default constructor: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> emptyMap;
		NAMESPACE::set<TESTED_TYPE2> emptyMap2;
		NAMESPACE::set<TESTED_TYPE3> emptyMap3;
		std::cout << GRN << "\n>> Empty set constructor OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insertion of int pairs test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE2> set2;
		set2.insert(1);
		set2.insert(3);
		set2.insert(2);
		set2.insert(4);
		NAMESPACE::set<TESTED_TYPE3> set3;
		set3.insert("Test1");
		set3.insert("Test3");
		set3.insert("Test2");
		set3.insert("Test4");
		set3.insert("Test4");
		std::cout << GRN << "\n>> Insert 4 pairs OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insertion of int pairs test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		for (int i = 0; i < 100000; i++) {
			set.insert((i + 1 % 3));
		}
		std::cout << GRN << "\n>> Insert 100000 pairs OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator forward test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		std::cout << std::endl << "PRINT SET:" << std::endl;
		NAMESPACE::set<TESTED_TYPE1>::iterator it;
		for (it = set.begin(); it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Iterator forward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator forward test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE3> set3;
		set3.insert("Test1");
		set3.insert("Test3");
		set3.insert("Test2");
		set3.insert("Test4");
		set3.insert("Test8");
		std::cout << std::endl << "PRINT SET:" << std::endl;
		NAMESPACE::set<TESTED_TYPE3>::iterator it;
		for (it = set3.begin(); it != set3.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Iterator forward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator backward test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		std::cout << std::endl << "PRINT SET:" << std::endl;
		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.end();
		it--;
		for (; it != set.begin(); --it)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Iterator backward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator backward test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE2> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		std::cout << std::endl << "PRINT SET:" << std::endl;
		NAMESPACE::set<TESTED_TYPE2>::iterator it = set.end();
		it--;
		for (; it != set.begin(); --it)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Iterator backward OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Iterator reverse test: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		std::cout << std::endl << "PRINT SET:" << std::endl;
		NAMESPACE::set<TESTED_TYPE1>::reverse_iterator it;
		for (it = set.rbegin(); it != set.rend(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Iterator reverse OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Range constructor: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);

		NAMESPACE::set<TESTED_TYPE1> set2(set.begin(), set.end());
		NAMESPACE::set<TESTED_TYPE1>::iterator it;
		for (it = set2.begin(); it != set2.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Range set constructor OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Copy constructor: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);

		NAMESPACE::set<TESTED_TYPE1> set2(set);
		NAMESPACE::set<TESTED_TYPE1>::iterator it;
		for (it = set2.begin(); it != set2.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Copy constructor set OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Assign operator: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);

		NAMESPACE::set<TESTED_TYPE1> set2 = set;
		NAMESPACE::set<TESTED_TYPE1>::iterator it;
		for (it = set2.begin(); it != set2.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n>> Assign operator OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Empty function: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		NAMESPACE::set<TESTED_TYPE1> set2;

		std::cout << "Is set empty? " << set.empty() << " should be false" << std::endl;
		std::cout << "Is set2 empty? " << set2.empty() << " should be true" << std::endl;

		std::cout << GRN << "\n>> Empty OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Size function: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		NAMESPACE::set<TESTED_TYPE1> set2;

		std::cout << "What is set size? " << set.size() << " - should be 5" << std::endl;
		std::cout << "What is set2 size? " << set2.size() << " - should be 0" << std::endl;

		std::cout << GRN << "\n>> Size OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Max Size function: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		set.insert(8);
		NAMESPACE::set<TESTED_TYPE1> set2;

		std::cout << set.max_size() << std::endl;
		std::cout << set2.max_size() << std::endl;

		std::cout << GRN << "\n>> Max Size OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insert by value function: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		std::cout << "Return of first insert is " << set.insert(8).second << std::endl;
		std::cout << "Return of re-insert is " << set.insert(8).second << std::endl;
		set.insert(10);

		NAMESPACE::set<TESTED_TYPE1>::iterator it;
		for (it = set.begin(); it != set.end(); it++)
			std::cout << "Iterator value: " << *(it)<< std::endl;
		std::cout << GRN << "\n> Insert by value OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insert by pos + value function: " << NC << std::endl;

		NAMESPACE::set<TESTED_TYPE1> set;
		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();

		std::cout << "Return of first insert is at " << *(set.insert(it, 1)) << std::endl;
		std::cout << "Return of re-insert is at " << *(set.insert(it, 1)) << std::endl;

		for (it = set.begin(); it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Insert by pos OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insert by iterator range function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		NAMESPACE::set<TESTED_TYPE1>::iterator ite = set.end();
		NAMESPACE::set<TESTED_TYPE1> set2;

		set2.insert(set.begin(), ite);

		for (it = set2.begin(); it != set2.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Insert by iterator range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by key function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);

		std::cout << "Return of first erase is at " << set.erase(2) << std::endl;
		std::cout << "Return of re-erase is at " << set.erase(2) << std::endl;

		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		for (; it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Erase by key range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by key function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE3> set3;
		set3.insert("Test1");
		set3.insert("Test3");
		set3.insert("Test2");
		set3.insert("Test4");
		set3.insert("Test8");
		std::cout << "Return of first erase is at " << set3.erase("Test2") << std::endl;
		std::cout << "Return of re-erase is at " << set3.erase("Test2") << std::endl;

		NAMESPACE::set<TESTED_TYPE3>::iterator it = set3.begin();
		for (; it != set3.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Erase by key range OK " << NC << std::endl;
	}
	{
		NAMESPACE::set<TESTED_TYPE3> mp;
		mp.insert("Test1");
		mp.insert("Test3");
		mp.insert("Test2");
		mp.insert("Test4");
		mp.insert("Test8");

		mp.erase(--(--(--mp.end())), mp.end());
		std::cout << std::endl << "PRINT SET:" << std::endl;
		NAMESPACE::set<TESTED_TYPE3>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by position (iterator) function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);

		set.erase(set.begin());

		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		for (; it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Erase by position (iterator) range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Erase by iterator range function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);

		set.erase(set.begin(), set.end());

		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		for (; it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Erase by iterator range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Clear function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);

		set.clear();

		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		for (; it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Clear OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Swap function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE1> set2;
		set2.insert(7);
		set2.insert(9);
		set2.insert(8);

		set.swap(set2);
		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		for (; it != set.end(); it++)
			std::cout << "Iterator value: " << *(it) << std::endl;
		std::cout << GRN << "\n> Swap OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Key & Value comp functions: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.begin();
		NAMESPACE::set<TESTED_TYPE1>::iterator ite = set.end();
		ite--;
		std::cout << "Key comp: " << (set.key_comp())(*it, *ite) << std::endl;
		std::cout << "Value comp: " << (set.value_comp())(*it, 4) << std::endl;
		std::cout << GRN << "\n> Key & Value comp OK " << NC << std::endl;
	}
	{
		NAMESPACE::set<float>	set;

		set.insert(2.3);
		set.insert(1.4);
		set.insert(0.3);
		set.insert(4.2);
		static unsigned int i = 0;
		std::cout << "Max Size " << set.max_size() << std::endl;
		NAMESPACE::set<float>::const_iterator it1;
		NAMESPACE::set<float>::const_iterator it2;
		for (it1 = set.begin(); it1 != set.end(); ++it1)
			for (it2 = set.begin(); it2 != set.end(); ++it2){
				bool res[2];

				std::cout << "\t-- [" << ++i << "] --" << std::endl;
				res[0] = set.key_comp()(*it1, *it2);
				res[1] = set.value_comp()(*it1, *it2);
				std::cout << "with [" << *it1 << " and " << *it2 << "]: ";
				std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
			}
	}
	{
		std::cout << YEL << "\n>> Find by key function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE1>::iterator it = set.find(3);
		std::cout << "Find [3]: [" << *it << "]" << std::endl;
		std::cout << GRN << "\n> Find by key OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const find by key function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		const NAMESPACE::set<TESTED_TYPE1> set1 = set;
		const NAMESPACE::set<TESTED_TYPE1> set2;
		NAMESPACE::set<TESTED_TYPE1>::const_iterator it = set1.find(4);
		std::cout << "Find [4] in set1 (exists): [" << *it << "]" << std::endl;
		std::cout << GRN << "\n> Const find by key OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Count function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		std::cout << "Count if pair [4] exists: " << set.count(4) << std::endl;
		std::cout << "Count if key 5 exists (it doesn't): " << set.count(5) << std::endl;
		std::cout << GRN << "\n> Count OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Lowerbound function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE1>::iterator it1 = set.lower_bound(4);
		std::cout << "Lowerbound of pair [3] is: [" << *it1 << "]" << std::endl;
		std::cout << GRN << "\n> Lowerbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Lowerbound function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		const NAMESPACE::set<TESTED_TYPE1> set1 = set;
		NAMESPACE::set<TESTED_TYPE1>::const_iterator it1 = set1.lower_bound(4);
		std::cout << "Const Lowerbound of pair [3] is: [" << *it1 << "]" << std::endl;
		std::cout << GRN << "\n> Const Lowerbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Upperbound function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::set<TESTED_TYPE1>::iterator it1 = set.upper_bound(3);
		std::cout << "Upperbound of pair [3] is: [" << *it1 << "]" << std::endl;
		std::cout << GRN << "\n> Upperbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Upperbound function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		const NAMESPACE::set<TESTED_TYPE1> set1 = set;
		NAMESPACE::set<TESTED_TYPE1>::const_iterator it1 = set1.upper_bound(3);
		std::cout << "Const Upperbound of pair [3] is: [" << *it1 << "]" << std::endl;
		std::cout << GRN << "\n> Const Upperbound OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Equal range function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		NAMESPACE::pair<NAMESPACE::set<TESTED_TYPE1>::iterator, NAMESPACE::set<TESTED_TYPE1>::iterator> pairIts;
		pairIts = set.equal_range(3);
		std::cout << "Equal range of pair [3] is: [" << *(pairIts.first) << " - " <<  *(pairIts.second)<< "]" << std::endl;
		pairIts = set.equal_range(5);
		std::cout << GRN << "\n> Equal range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Const Equal range function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		set.insert(3);
		set.insert(2);
		set.insert(4);
		const NAMESPACE::set<TESTED_TYPE1> set1 = set;
		NAMESPACE::pair<NAMESPACE::set<TESTED_TYPE1>::const_iterator, NAMESPACE::set<TESTED_TYPE1>::const_iterator> pairIts;
		pairIts = set1.equal_range(3);
		std::cout << "Const Equal range of pair [3] is: [" << *(pairIts.first) << " - " <<  *(pairIts.second)<< "]" << std::endl;
		pairIts = set1.equal_range(5);
		std::cout << GRN << "\n> Const Equal range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Get Allocator function: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set;
		set.insert(1);
		NAMESPACE::set<TESTED_TYPE1> set2;
		std::cout << "Allocator test on max size set 1: " << set.get_allocator().max_size() << std::endl;
		std::cout << "Allocator test on max size set 2: " << set2.get_allocator().max_size() << std::endl;
		std::cout << GRN << "\n> Get Allocator range OK " << NC << std::endl;
	}
	{
		std::cout << YEL << std::endl << ">> Test of operators for comparison: " << NC << std::endl;
		NAMESPACE::set<TESTED_TYPE1> set1, set2, set3;

		set1.insert(1);
		set2.insert(1);
		set3.insert(1);
		set1.insert(2);
		set2.insert(2);
		set3.insert(2);
		set1.insert(3);
		set2.insert(3);
		set3.insert(3);
		set3.insert(4);
		std::cout << "set1 == set2 ? Result is = " << (set1 == set2) << std::endl;
		if ((set1 == set2) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "set2 == set3 ? Result is = " << (set2 == set3) << std::endl;
		if ((set2 == set3) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "set2 >= set3 ? Result is = " << (set2 >= set3) << std::endl;
		if ((set2 >= set3) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO"<< NC << std::endl;
		std::cout << "set2 > set3 ? Result is = " << (set2 > set3) << std::endl;
		if ((set2 > set3) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "set2 <= set3 ? Result is = " << (set2 <= set3) << std::endl;
		if ((set2 <= set3) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "set2 < set3 ? Result is = " << (set2 < set3) << std::endl;
		if ((set2 < set3) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "set2 != set3 ? Result is = " << (set2 != set3) << std::endl;
		if ((set2 != set3) == 1)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
		std::cout << "set1 != set2 ? Result is = " << (set1 != set2) << std::endl;
		if ((set1 != set2) == 0)
			std::cout << GRN << "OK" << NC << std::endl;
		else
			std::cout << RED << "KO" << NC << std::endl;
	}
	return 0;
}
