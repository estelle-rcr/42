#include "vector.hpp"
#include <iostream>
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
#define TESTED_TYPE int
#endif

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

void	tests_vector(void) {
	std::cout << REDB << "\n>>> TESTS FOR VECTOR <<<" << NC << std::endl;

	// CONSTRUCTORS

	std::cout << GRN << "\n>> Create 5 Vectors of tested type: " << NC << std::endl;
	NAMESPACE::vector<TESTED_TYPE> intVect;
	NAMESPACE::vector<TESTED_TYPE> first;
	std::cout << NEW << "\n>> vector default constructor OK " << NC << std::endl;
	NAMESPACE::vector<TESTED_TYPE> second (4,100);
	std::cout << NEW << "\n>> vector value constructor OK " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE> third (second.begin(),second.end());
		NAMESPACE::vector<TESTED_TYPE>::iterator it = third.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = third.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Size : " << third.size() << std::endl;
		std::cout << "Capacity : " << third.capacity() << std::endl;
		std::cout << NEW << "\n>> vector iterator constructor OK " << NC << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}
	NAMESPACE::vector<TESTED_TYPE> fourth (second);
	std::cout << NEW << "\n>> vector copy constructor OK " << NC << std::endl;
	NAMESPACE::vector<TESTED_TYPE> fifth;
	fifth = fourth;
	std::cout << NEW << "\n>> vector assignation constructor OK " << NC << std::endl;

	// Test const vect
	const NAMESPACE::vector<TESTED_TYPE> intConstVect(10);

	std::cout << NEW << "\nOK constructors" << NC << std::endl;

	// ITERATORS - TESTS ON WHILE & FOR LOOP

	std::cout << GRN << "\n>> FT Iterators - while loop: " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE> sixth(4,100);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = sixth.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = sixth.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	std::cout << GRN << "\n>> FT Iterators - for loop: " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE> seventh(4,100);
		NAMESPACE::vector<TESTED_TYPE>::iterator it;
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = seventh.end();
		for (it=seventh.begin(); it < ite; it++)
			std::cout << ' ' << *it;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	try {
		const int size = 5;
		NAMESPACE::vector<TESTED_TYPE> vct(size);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
		NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

		for (int i = 0; i < size; ++i)
			it[i] = (size - i) * 5;
		it = vct.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

		std::cout << "Pre inc" << std::endl;
		it_tmp = ++it;
		std::cout << *it_tmp << " | " << *it << std::endl;

		std::cout << "Pre dec" << std::endl;
		it_tmp = --it;
		std::cout << *it_tmp << " | " << *it << std::endl;

		std::cout << "Post inc" << std::endl;
		it_tmp = it++;
		std::cout << *it_tmp << " | " << *it << std::endl;

		std::cout << "Post dec" << std::endl;
		it_tmp = it--;
		std::cout << *it_tmp << " | " << *it << std::endl;
		std::cout << std::endl;

		it = it + 5;
		it = 1 + it;
		it = it - 4;
		std::cout << *(it += 2) << std::endl;
		std::cout << *(it -= 1) << std::endl;

		*(it -= 2) = 42;
		*(it += 2) = 21;

		std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
		std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

		std::cout << "(it == const_it): " << (ite == it) << std::endl;
		std::cout << "(const_ite - it): " << (ite - it) << std::endl;
		std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		std::cout << "size: " << vct.size() << std::endl;
		}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	// REVERSE_ITERATORS

	try {
		NAMESPACE::vector<TESTED_TYPE> myvector (3,100);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = myvector.begin();
		it = myvector.insert ( it , 21);
		it = myvector.insert ( ++it , 22);
		std::cout << "\nmyvector contains:" << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit = myvector.rbegin();
		NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rite = myvector.rend();
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			rit++;
		}
		std::cout << "\nmyvector contains:" << std::endl;
		for (rit=myvector.rbegin(); rit < rite; rit++)
			std::cout << ' ' << *rit;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	// CAPACITY FUNCTIONS

	std::cout << GRN << "\n>> Size: " << NC << std::endl;
	std::cout << intVect.size() << std::endl;

	std::cout << GRN << "\n>> Max_size: " << NC << std::endl;
	std::cout << intVect.max_size() << std::endl;

	std::cout << GRN << "\n>> Resize 8: " << NC << std::endl;
	intVect.resize(8);
	std::cout << "Size = " << intVect.size() << std::endl;
	std::cout << "Capacity = " << intVect.capacity() << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE>::iterator it = intVect.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = intVect.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	std::cout << GRN << "\n>> Resize 10, 100: " << NC << std::endl;
	intVect.resize(10, 100);
	std::cout << "Size = " << intVect.size() << std::endl;
	std::cout << "Capacity = " << intVect.capacity() << std::endl;
	std::cout << "Iterate through vector = " << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE>::iterator it = intVect.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = intVect.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	std::cout << GRN << "\n>> Resize 12, 100: " << NC << std::endl;
	intVect.resize(12, 100);
	std::cout << "Capacity = " << intVect.capacity() << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE>::iterator it = intVect.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = intVect.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	std::cout << GRN << "\n>> Resize 16, 100: " << NC << std::endl;
	intVect.resize(16, 100);
	std::cout << "Capacity = " << intVect.capacity() << std::endl;

	std::cout << GRN << "\n>> Resize 18, 100: " << NC << std::endl;
	intVect.resize(18, 100);
	std::cout << "Capacity = " << intVect.capacity() << std::endl;

	// ISSUE with value between n and capacity:
	std::cout << GRN << "\n>> Resize 20, 100: " << NC << std::endl;
	intVect.resize(20, 100);
	std::cout << "Capacity = " << intVect.capacity() << std::endl;

	std::cout << GRN << "\n>> Capacity: " << NC << std::endl;
	std::cout << "Capacity = " << intVect.capacity() << std::endl;

	std::cout << GRN << "\n>> Empty: " << NC << std::endl;
	std::cout << "Capacity = " << intVect.empty() << std::endl;

	std::cout << GRN << "\n>> Reserve: " << NC << std::endl;
	intVect.reserve(intVect.capacity() + 2);
	std::cout << "Capacity = " << intVect.capacity() << std::endl;

	// ELEMENT ACCESS

	std::cout << GRN << "\n>> Operator []: " << NC << std::endl;
	std::cout << "Position 1 = " << intVect[1] << std::endl;

	std::cout << GRN << "\n>> Operator const []: " << NC << std::endl;
	std::cout << "Position 1 in const vector = " << intConstVect[1] << std::endl;

	std::cout << GRN << "\n>> Ref at : " << NC << std::endl;
	std::cout << "ref at 2 = " << intVect.at(2) << std::endl;
	try {
		std::cout << "ref at 20 (out of range) = " << intVect.at(20) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}

	std::cout << GRN << "\n>> Ref on Const vector at : " << NC << std::endl;
	std::cout << "ref at 2 = " << intConstVect.at(2) << std::endl;
	try {
		std::cout << "ref at 20 (out of range) = " << intConstVect.at(20) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}

	std::cout << GRN << "\n>> Front : " << NC << std::endl;
	std::cout << "front value = " << intVect.front() << std::endl;

	std::cout << GRN << "\n>> Front Const vector : " << NC << std::endl;
	std::cout << "front value = " << intConstVect.front() << std::endl;

	std::cout << GRN << "\n>> Back : " << NC << std::endl;
	std::cout << "back/last value = " << intVect.back() << std::endl;

	std::cout << GRN << "\n>> Back Const vector : " << NC << std::endl;
	std::cout << "back/last value = " << intConstVect.back() << std::endl;


	// MODIFIERS

	std::cout << GRN << "\n>> Assign with iterators : " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		fifth.assign(it, ite) ;
		it = first.begin();
		ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	std::cout << GRN << "\n>> Assign : " << NC << std::endl;
	try {
		first.assign(8, 100);
		std::cout << first.size() << std::endl;
		std::cout << first.capacity() << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	try {
		first.assign(6, 50);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}

	std::cout << GRN << "\n>> Push_back : " << NC << std::endl;
	try {
		std::cout << "> 118 " << std::endl;
		intVect.push_back(118);
		std::cout << "Size = " << intVect.size() << std::endl;
		std::cout << "Capacity = " << intVect.capacity() << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}

	try {
		std::cout << "> 28 " << std::endl;
		intVect.push_back(28);
		std::cout << "Size = " << intVect.size() << std::endl;
		std::cout << "Capacity = " << intVect.capacity() << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}

	try {
		std::cout << "> 38 " << std::endl;
		intVect.push_back(38);
		std::cout << "Size = " << intVect.size() << std::endl;
		std::cout << "Capacity = " << intVect.capacity() << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}


	std::cout << GRN << "\n>> Pop_back : " << NC << std::endl;
	try {
		std::cout << "> 1st pop back " << std::endl;
		intVect.pop_back();
		std::cout << "Size = " << intVect.size() << std::endl;
		std::cout << "Capacity = " << intVect.capacity() << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}

	try {
		std::cout << "> 2nd pop back " << std::endl;
		intVect.pop_back();
		std::cout << "Size = " << intVect.size() << std::endl;
		std::cout << "Capacity = " << intVect.capacity() << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = first.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = first.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() " << std::endl;
	}


////	INSERT

	std::cout << GRN << "\n>> Insert: " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE> myvector (3,100);
		std::cout << "\nmyvector contains:" << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = myvector.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = myvector.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
		it = myvector.begin();
		it = myvector.insert ( it , 21);
		ite = myvector.end();
		std::cout << "\nmyvector contains:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
		it = myvector.begin();
		myvector.insert (it, 2, 30);
		ite = myvector.end();

		std::cout << "\nmyvector contains:" << std::endl;
		for (it=myvector.begin(); it < ite; it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	try {
		NAMESPACE::vector<TESTED_TYPE> seven(4,100);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = seven.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = seven.end()--;
		seven.insert(ite, 4, 15);
		it = seven.begin();
		ite = seven.end();
		std::cout << "\nmyvector contains:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "myvector size : " << seven.size() << std::endl;
		std::cout << "myvector capacity : " << seven.capacity() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}
	try {
		NAMESPACE::vector<TESTED_TYPE> sixth(4,100);
		NAMESPACE::vector<TESTED_TYPE>::iterator it = sixth.begin();
		sixth.insert(it, 1, 5);
		it = sixth.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = sixth.end();
		sixth.insert(ite, 4, 15);
		it = sixth.begin();
		ite = sixth.end();
		std::cout << "\nmyvector contains:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

	std::cout << GRN << "\n>> Insert with iterators: " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE> myvector (3,100);
		std::cout << "\nmyvector contains:" << std::endl;
		NAMESPACE::vector<TESTED_TYPE>::iterator it = myvector.begin();
		NAMESPACE::vector<TESTED_TYPE>::iterator ite = myvector.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
		it = myvector.begin();
		ite = myvector.end();
		NAMESPACE::vector<TESTED_TYPE> anothervector (4,40);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());
		it = myvector.begin();
		ite = myvector.end();
		std::cout << "\nmyvector contains:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
		it = myvector.begin();
		ite = myvector.end();
		myvector.insert(it+4,anothervector.begin() + 1,anothervector.end() - 1);
		it = myvector.begin();
		ite = myvector.end();
		std::cout << "\nmyvector contains:" << std::endl;
		for (it=myvector.begin(); it < ite; it++)
			std::cout << ' ' << *it;
		std::cout << std::endl;
		it = myvector.begin();
		ite = myvector.end();
		NAMESPACE::vector<TESTED_TYPE> anothervector2 (8,40);
		myvector.insert (ite,anothervector2.begin() + 2,anothervector2.end() - 3);
		it = myvector.begin();
		ite = myvector.end();
		std::cout << "\nmyvector contains:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
		std::cout << "myvector size : " << myvector.size() << std::endl;
		std::cout << "myvector capacity : " << myvector.capacity() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}


////	ERASE

	std::cout << GRN << "\n>> Erase at one emplacement + with a range of iterators: " << NC << std::endl;
	try {
		NAMESPACE::vector<TESTED_TYPE> myvector;
		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);
		// erase the 6th element
		myvector.erase (myvector.begin()+5);
		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);
		// erase last element
		myvector.erase (myvector.end() - 1);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << std::endl;
		std::cout << "myvector size : " << myvector.size() << std::endl;
		std::cout << "myvector capacity : " << myvector.capacity() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << " Raise exception e.what() "  << std::endl;
	}

//// TEST COMPARATORS
	std::cout << GRN << std::endl << ">> Test of operators for comparison: " << NC << std::endl;
	NAMESPACE::vector<TESTED_TYPE> myvector4, myvector5, myvector6;
	for (int i=1; i<=100; i++) myvector4.push_back(i + 1);
	for (int i=1; i<=100; i++) myvector5.push_back(i + 1);
	for (int i=1; i<=200; i++) myvector6.push_back(i + 1);
	std::cout << "myvector4 == myvector5 ? Result is = " << (myvector4 == myvector5) << std::endl;
	if ((myvector4 == myvector5) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector5 == myvector6 ? Result is = " << (myvector5 == myvector6) << std::endl;
	if ((myvector5 == myvector6) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector5 >= myvector6 ? Result is = " << (myvector5 >= myvector6) << std::endl;
	if ((myvector5 >= myvector6) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector5 > myvector6 ? Result is = " << (myvector5 > myvector6) << std::endl;
	if ((myvector5 > myvector6) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector5 <= myvector6 ? Result is = " << (myvector5 <= myvector6) << std::endl;
	if ((myvector5 <= myvector6) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector5 < myvector6 ? Result is = " << (myvector5 < myvector6) << std::endl;
	if ((myvector5 < myvector6) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector5 != myvector6 ? Result is = " << (myvector5 != myvector6) << std::endl;
	if ((myvector5 != myvector6) == 1)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
	std::cout << "myvector4 != myvector5 ? Result is = " << (myvector4 != myvector5) << std::endl;
	if ((myvector4 != myvector5) == 0)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
