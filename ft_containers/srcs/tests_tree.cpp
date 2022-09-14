#include "rbtree.hpp"
#include "pair.hpp"
#include "rbtree_iterator.hpp"

#define NC "\e[0m"
#define CYN "\e[0;36m"
#define YEL "\e[0;33m"
#define GRN "\e[0;32m"
#define REDB "\e[41m"

////
//// HOW TO USE:
//// Change the TESTED_TYPE variable to test different types: int, char, long long, etc.
////

#ifndef TESTED_TYPE
#define TESTED_TYPE	int
#endif

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

int tests_tree(void)
{
		std::cout << REDB << "\n>>> TESTS FOR TREE <<<" << NC << std::endl;
		std::cout << YEL << "\n>> Tests on the RB TREE (insertion, deletion): " << NC << std::endl;
	{
		std::cout << YEL << "\n>> Insertion of int + getbegin + getend test: " << NC << std::endl;
		NAMESPACE::RBTree<int> tree;

		tree.insert(77);
		tree.insert(64);
		tree.insert(5);
		tree.insert(14);
		tree.insert(31);
		tree.insert(22);
		tree.insert(21);

		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();

		tree.deleteNode(22);

		std::cout << std::endl << "PRINT TREE AFTER DELETE" << std::endl;
		tree.printTree();

		std::cout << std::endl << "Begin value : " << tree.getBegin()->value << std::endl;
		std::cout << "End value : " << tree.getEnd()->value << std::endl;
		std::cout << GRN << "\n>> Insert int + getbegin + getend OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insertion of pairs test: " << NC << std::endl;
		NAMESPACE::pair<int, int> pair(1, 1);
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> > tree;
		tree.insert(pair);
		NAMESPACE::pair<int, int> pair3(3, 3);
		tree.insert(pair3);
		NAMESPACE::pair<int, int> pair2(2, 22);
		tree.insert(pair2);
		NAMESPACE::pair<int, int> pair4(4, 1);
		tree.insert(pair4);
		tree.insert(pair);
		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();
		std::cout << GRN << "\n>> Insert pair OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Deletion test: " << NC << std::endl;
		NAMESPACE::RBTree<int> tree;

		tree.insert(127);
		tree.insert(100);
		tree.insert(98);
		tree.insert(105);
		tree.insert(111);
		tree.insert(121);
		tree.insert(121);
		tree.insert(105);

		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();
		try {
			tree.deleteNode(22);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		std::cout << GRN << "\n>> Deletion OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Insertion + deletion of pairs test: " << NC << std::endl;
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> > tree;
		NAMESPACE::pair<int, int> pair(1, 1);
		tree.insert(pair);
		NAMESPACE::pair<int, int> pair3(3, 3);
		tree.insert(pair3);
		NAMESPACE::pair<int, int> pair2(2, 22);
		tree.insert(pair2);
		NAMESPACE::pair<int, int> pair4(4, 1);
		tree.insert(pair4);
		try {
			tree.deleteNode(pair2);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();
		std::cout << GRN << "\n>> Delete pair OK " << NC << std::endl;
	}
	{
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> > tree;
		NAMESPACE::pair<int, int> pair(1, 1);
		tree.insert(pair);
		NAMESPACE::pair<int, int> pair3(3, 3);
		tree.insert(pair3);
		NAMESPACE::pair<int, int> pair2(2, 22);
		tree.insert(pair2);

		try {
			tree.deleteNode(pair2);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();
		std::cout << GRN << "\n>> Delete root pair OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Multiple Insertion + Deletion: " << NC << std::endl;
		NAMESPACE::RBTree<int> tree;
		tree.insert(10);
		tree.insert(150);
		tree.insert(100);
		tree.insert(50);
		tree.insert(15);
		tree.insert(40);
		tree.insert(8);
		tree.insert(12);
		tree.insert(11);

		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();
		try {
			tree.deleteNode(150);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		std::cout << std::endl << "PRINT TREE AFTER DELETE" << std::endl;
		tree.printTree();
		try {
			tree.deleteNode(15);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		try {
			tree.deleteNode(40);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		try {
			tree.deleteNode(50);
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		std::cout << std::endl << "PRINT TREE AFTER DELETE" << std::endl;
		tree.printTree();
		tree.insert(151);
		tree.insert(149);
		std::cout << std::endl << "PRINT TREE AFTER INSERT" << std::endl;
		tree.printTree();
		std::cout << GRN << "\n>> Multiple Insertion + Deletion OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Complex test on deletion: " << NC << std::endl;
		NAMESPACE::RBTree<NAMESPACE::pair<int, std::string> > tree;
		NAMESPACE::pair<int, std::string> pair(0, "null");
		pair = ft::make_pair(42, "test1");
		tree.insert(pair);
		pair = ft::make_pair(50, "test2");
		tree.insert(pair);
		pair = ft::make_pair(25, "test3");
		tree.insert(pair);
		pair = ft::make_pair(46, "test4");
		tree.insert(pair);
		pair = ft::make_pair(21, "test5");
		tree.insert(pair);
		pair = ft::make_pair(30, "test6");
		tree.insert(pair);
		pair = ft::make_pair(55, "test7");
		tree.insert(pair);
		pair = ft::make_pair(18, "test8");
		tree.insert(pair);
		pair = ft::make_pair(23, "test9");
		tree.insert(pair);
		pair = ft::make_pair(28, "test10");
		tree.insert(pair);
		pair = ft::make_pair(35, "test11");
		tree.insert(pair);
		pair = ft::make_pair(44, "test12");
		tree.insert(pair);
		pair = ft::make_pair(48, "test13");
		tree.insert(pair);
		pair = ft::make_pair(53, "test14");
		tree.insert(pair);
		pair = ft::make_pair(80, "test15");
		tree.insert(pair);
		pair = ft::make_pair(12, "test16");
		tree.insert(pair);
		pair = ft::make_pair(20, "test17");
		tree.insert(pair);
		pair = ft::make_pair(22, "test18");
		tree.insert(pair);
		pair = ft::make_pair(24, "test19");
		tree.insert(pair);
		pair = ft::make_pair(27, "test20");
		tree.insert(pair);
		pair = ft::make_pair(29, "test21");
		tree.insert(pair);
		pair = ft::make_pair(33, "test22");
		tree.insert(pair);
		pair = ft::make_pair(38, "test23");
		tree.insert(pair);
		pair = ft::make_pair(90, "test24");
		tree.insert(pair);
		pair = ft::make_pair(60, "test25");
		tree.insert(pair);
		pair = ft::make_pair(54, "test26");
		tree.insert(pair);
		std::cout << std::endl << "PRINT TREE AFTER INSERTION" << std::endl;
		tree.printTree();
		pair = ft::make_pair(25, "test3");
		tree.deleteNode(pair);
		pair = ft::make_pair(55, "test7");
		tree.deleteNode(pair);
		pair = ft::make_pair(24, "test19");
		tree.deleteNode(pair);
		pair = ft::make_pair(54, "test26");
		tree.deleteNode(pair);
		pair = ft::make_pair(60, "test25");
		tree.deleteNode(pair);
		pair = ft::make_pair(50, "test2");
		tree.deleteNode(pair);
		std::cout << std::endl << "PRINT TREE AFTER DELETE" << std::endl;
		tree.printTree();
		std::cout << GRN << "\n>> Complex test OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Tests search by data" << NC << std::endl;
		NAMESPACE::RBTree<int> tree;
		try {
			tree.insert(10);
			tree.insert(150);
			tree.insert(100);
			tree.insert(50);
			tree.insert(15);
			tree.insert(40);
			try {
				std::cout << "Is in tree: " << tree.isInTree(50) << std::endl;
			}
			catch (std::exception &e) {
				std::cout <<  e.what() << std::endl;
			}
			try {
				std::cout << "Is in tree: " << tree.isInTree(148) << std::endl;
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			std::cout << std::endl << "PRINT TREE" << std::endl;
			tree.printTree();
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		std::cout << GRN << "\n>> Search by type OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n>> Tests search by pair" << NC << std::endl;
		NAMESPACE::pair<int, int> pair(1, 1);
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> > tree;
		tree.insert(pair);
		NAMESPACE::pair<int, int> pair3(3, 3);
		tree.insert(pair3);
		NAMESPACE::pair<int, int> pair2(2, 22);
		tree.insert(pair2);
		NAMESPACE::pair<int, int> pair4(4, 1);
		tree.insert(pair4);
		NAMESPACE::pair<int, int> nonexistingpair(1, 18);
		try {
			std::cout << "Pair: " << tree.searchTree(pair2)->value << std::endl;
			std::cout << "Is in tree: " << tree.isInTree(pair2) << std::endl;
		}
		catch (std::exception &e) {
			std::cout <<  e.what() << std::endl;
		}
		try {
			std::cout << "Pair: " << tree.searchTree(nonexistingpair)->value << std::endl;
			std::cout << "Is in tree: " << tree.isInTree(nonexistingpair) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl << "PRINT TREE" << std::endl;
		tree.printTree();
		std::cout << GRN << "\n>> Search by pair OK " << NC << std::endl;
	}
	{
		std::cout << YEL << "\n Tests RBT : " << NC << std::endl;
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> > tree;
		NAMESPACE::pair<int, int> pair('c', 18);
		tree.insert(pair);
		NAMESPACE::pair<int, int> pair3('a', 3);
		tree.insert(pair3);
		NAMESPACE::pair<int, int> pair2('b', 22);
		tree.insert(pair2);
		NAMESPACE::pair<int, int> pair4('d', 1);
		tree.insert(pair4);
		NAMESPACE::rbtree_iterator<NAMESPACE::pair<int, int> > it;

		NAMESPACE::RBTree<NAMESPACE::pair<int, int> >::iterator itb = tree.getBegin();
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> >::iterator ite = tree.getEnd();
		NAMESPACE::RBTree<NAMESPACE::pair<int, int> >::iterator ite2 = tree.getEndSuccessor();
		std::cout << "Iterator begin: " << *itb << std::endl;
		std::cout << "Iterator on last element: " << *ite << std::endl;
		std::cout << "Iterator end: " << *ite2 << std::endl;
		itb++;
		std::cout << "Iterator begin++: " << *itb << std::endl;
		itb--;
		std::cout << "Iterator begin--: " << *itb << std::endl;
	}
	return 0;
}
