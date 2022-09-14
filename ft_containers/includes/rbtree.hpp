#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include <queue>
#include <algorithm>
#include "rbtree_node.hpp"
#include "rbtree_iterator.hpp"

#define REDC	"\e[0;31m"
#define GRN 	"\e[0;32m"
#define NC		"\e[0m"

namespace	ft {

	template < typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class RBTree {
			typedef typename Alloc::template rebind<node<T> >::other 		nodeAllocator;

		public:
			typedef typename Alloc::size_type 								size_type;
			typedef ft::node<T>												Node;
			typedef ft::node<T>*											NodePtr;
			typedef ft::rbtree_iterator<T>									iterator;
			typedef ft::rbtree_iterator<const T>							constIterator;

		protected:
			typedef ptrdiff_t	difference_type;
			ft::node<T>*		root;
			ft::node<T>*		nil;
			ft::node<T>*		end;
			T					_valueType;
			size_type 			_size;
			Compare				_comp;
			nodeAllocator		_alloc;

		public:

		// *** CONSTRUCTORS ***

			RBTree(Compare c = Compare()) : _comp(c), _alloc(nodeAllocator()) {
				Node nilNode;
				this->nil = _alloc.allocate(1);
				_alloc.construct(this->nil, nilNode);
				this->nil->setPointers(nil);
				this->end = nil;
				this->root = nil;
				this->_size = 0;
			}

			~RBTree() {
				deleteNodes(root);
				_alloc.destroy(nil);
				_alloc.deallocate(nil, 1);
			}

			// *** INSERT FUNCTIONS ***

			NodePtr insert(const T &value) {
				Node newNode(value);
				NodePtr ptr = _alloc.allocate(1);
				NodePtr	pos;

				newNode.setPointers(nil);
				_alloc.construct(ptr, newNode);
				if ((pos = searchTree(value)) != nil) {
					_alloc.destroy(ptr);
					_alloc.deallocate(ptr, 1);
					return (pos);
				}
				root = insertHelper(root, ptr);
				fixViolation(ptr);
				_size += 1;
				setEndSuccessor();
				return (ptr);
			}

			void insert(iterator first, iterator last) {
				for (; first != last; first++) {
					insert(*first);
				}
			}

			// *** DELETE FUNCTION ***

			size_type deleteNode(const T &value) {
				int res = 0;
				if (deleteHelper(value) == true) {
					nil->setPointers(nil);
					_size -= 1;
					res = 1;
				}
				setEndSuccessor();
				return (res);
			}

			// *** PUBLIC SEARCH FUNCTIONS ***

			unsigned int isInTree(const T &value) const {
				return (searchTree(value) != nil ? 1 : 0);
			}

			NodePtr searchTree(const T &value) const {
				return searchTreeHelper(this->root, value);
			}

			// *** HELPERS ***

			size_type getSize() const { return (this->_size); };

			void swap(RBTree &x) {
				std::swap(root, x.root);
				std::swap(nil, x.nil);
				std::swap(end, x.end);
				std::swap(_size, x._size);
			}

			void printTree() {
				if (root) {
					printHelper(this->root, "", true);
				}
			};

			size_type	maxSize(void) const {
				return std::allocator< ft::node<T> >().max_size();
			}

			// *** GET ROOT, NIL, BEGIN AND END ***

			iterator getRoot() const {
				return (iterator(root));
			}

			NodePtr getNil() const {
				return (this->nil);
			}

			void setEndSuccessor (void) {
				NodePtr end;
				end = getEnd();
				end->right = this->end;
				this->end->parent = end;
			}

			NodePtr getEndSuccessor(void) const {
				return end->right;
			}

			NodePtr getBegin(void) const {
				return minimum(this->root);
			}

			NodePtr getEnd(void) const {
				return maximum(this->root);
			}


		protected:

		// *** INSERTION ***

		// Rotate

			void updateParentsChildren(NodePtr node, NodePtr newNode) {
				if (node->parent == nil) {
					root = newNode;
				}
				else if (node->isLeftChild())
					node->parent->setLeft(newNode);
				else
					node->parent->setRight(newNode);
			}

			void rotateLeft(NodePtr &node) {
				NodePtr rightNode = node->right;
				node->setRight(rightNode->left);
				if (node->right != nil)
					node->right->setParent(node);
				rightNode->setLeft(node);
				rightNode->setParent(node->parent);
				updateParentsChildren(node, rightNode);
				node->setParent(rightNode);
			}

			void rotateRight(NodePtr &node) {
				NodePtr leftNode = node->left;

				node->setLeft(leftNode->right);
				if (node->left != nil)
					node->left->setParent(node);
				leftNode->setRight(node);
				leftNode->setParent(node->parent);
				updateParentsChildren(node, leftNode);
				node->setParent(leftNode);
			}

			// Handle left children / right children / parent's children

			void	handleLeftChildren(NodePtr node, NodePtr parent, NodePtr grandParent) {
				bool hasRotated = false;

				if (node->isRightChild()) {
					rotateLeft(parent);
					hasRotated = true;
				}
				if (hasRotated == true)
					node->flipColor();
				else
					parent->flipColor();
				if (grandParent != nil)
					grandParent->flipColor();
				rotateRight(grandParent);
				if (node != root && node->isLeftChild())
					fixViolation(parent);
				else if (node != root && !node->isLeftChild())
					fixViolation(grandParent);

			}

			void	handleRightChildren(NodePtr node, NodePtr parent, NodePtr grandParent) {
				bool hasRotated = false;

				if (node->isLeftChild()) {
					rotateRight(parent);
					hasRotated = true;
				}
				if (hasRotated == true)
					node->flipColor();
				else
					parent->flipColor();
				if (grandParent != nil)
					grandParent->flipColor();
				rotateLeft(grandParent);
				if (node != root && node->isLeftChild())
					fixViolation(grandParent);
				else if (node != root && !node->isLeftChild())
					fixViolation(parent);
			}


			// Fix violations of the insertion by recoloring and rotating nodes

			void	handleRecolor(NodePtr parent, NodePtr uncle, NodePtr grandParent) {
				uncle->flipColor();
				parent->flipColor();
				grandParent->flipColor();
				fixViolation(grandParent);
			}

			void	fixViolation(NodePtr &node)
			{
				NodePtr parent = node->parent;
				if (node != root && node->color == RED && parent->color == RED) {
					NodePtr grandParent = node->parent->parent;
					NodePtr	uncle;
					if (grandParent == nil)
						uncle = nil;
					else
						uncle = (parent->isLeftChild() ? grandParent->right : grandParent->left);
					if (uncle != nil && uncle->color == RED)
						handleRecolor(uncle, parent, grandParent);
					else if (parent && parent->isLeftChild())
						handleLeftChildren(node, parent, grandParent);
					else if (parent && !parent->isLeftChild())
						handleRightChildren(node, parent, grandParent);
				}
				root->color = BLACK;
			}

			// Main recursive function to insert a new node with given key

			NodePtr	insertHelper(NodePtr node, NodePtr ptr)
			{
				if (root == this->nil) {
					ptr->color = BLACK;
					root = ptr;
					return ptr;
				}
				if (node == nil)
					return (ptr);
				else if (_comp(ptr->value, node->value) == true) {
					node->left = insertHelper(node->left, ptr);
					node->left->setParent(node);
				}
				else if (_comp(node->value, ptr->value) == true) {
					node->right = insertHelper(node->right, ptr);
					node->right->setParent(node);
				}
				return node;
			}

		//  *** DELETION ***

		// Function for fixing Red/black properties after deletion violated them

		NodePtr	getSibling(NodePtr node) {
			if (node->isLeftChild() && node->parent->right != nil)
				return (node->parent->right);
			else if (node->isRightChild() && node->parent->left != nil)
				return (node->parent->left);
			return nil;
		}

		void	handleRedSibling(NodePtr node, NodePtr sibling) {
			sibling->color = BLACK;
			node->parent->color = RED;
			if (node == node->parent->left)
				rotateLeft(node->parent);
			else
				rotateRight(node->parent);
		}

		bool	blackNephews(NodePtr node) {
			if (!(getSibling(node)->left == nil || (getSibling(node)->left != nil
				&& getSibling(node)->left->color == BLACK)))
				return false;
			else if (!(getSibling(node)->right == nil ||
				getSibling(node)->right->color == BLACK))
				return false;
			return true;
		}

		void	handleBlackSiblings(NodePtr node, NodePtr sibling) {
			// case 5: Black sibling with at least one red child + nephew is black
			if (node->isLeftChild() && (sibling->right == nil || sibling->right->color == BLACK)) {
				sibling->left->color = BLACK;
				sibling->color = RED;
				rotateRight(sibling);
				sibling = getSibling(node);
			}
			else if (!node->isLeftChild() && (sibling->left == nil || sibling->left->color == BLACK)) {
				sibling->right->color = BLACK;
				sibling->color = RED;
				rotateLeft(sibling);
				sibling = getSibling(node);
			}
			// case 6: Black sibling with at least one red child + nephew is red
			sibling->color = node->parent->color;
			node->parent->color = BLACK;
			if (node->isLeftChild()) {
				sibling->right->color = BLACK;
				rotateLeft(node->parent);
			}
			else {
				sibling->left->color = BLACK;
				rotateRight(node->parent);
			}
		}

		// Main function for fixing violated Red/black tree properties
		void	fixRedBlackProperties(NodePtr node) {			
			if (node == root)							// case 1: root, end of recursion
				return ;
			NodePtr sibling = getSibling(node);
			if (sibling->color == RED) {				// case 2: red sibling
				handleRedSibling(node, sibling);
				sibling = getSibling(node);
				if (sibling == nil)
					return ;
			}
			if (sibling->color == BLACK && blackNephews(node) == true) {
				sibling->color = RED;
				if (node->parent->color == RED)			// Case 3: Black sibling with 2 black children & red parent
					node->parent->color = BLACK;
				else									// Case 4: Black sibling with two black children + black parent
					fixRedBlackProperties(node->parent);
			}
			else {										// Case 5 & 6: Black sibling with at least 1 red child
				handleBlackSiblings(node, sibling);
			}
		}

		// Copy successor by using tmp as key is const
		void copySuccessor(NodePtr node, NodePtr successor) {
			NodePtr newNode(successor);
			NodePtr tmp = _alloc.allocate(1);
		
			_alloc.construct(tmp, newNode);
			tmp->setPointers(nil);
			tmp->setLeft(node->left);
			tmp->setRight(node->right);
			tmp->left->setParent(tmp);
			tmp->right->setParent(tmp);
			tmp->setParent(node->parent);
			tmp->nil = nil;
			if (root == node)
				root = tmp;
			if (node->isLeftChild())
				node->parent->setLeft(tmp);
			else
				node->parent->setRight(tmp);
			if (nil->right == node)
				nil->right = tmp;
			if (nil->left == node)
				nil->left = tmp;
			tmp->color = node->color;
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			node = tmp;
		}

		// Deletion of a Parent Node in the cases of having children or not
		NodePtr	deleteParentNode(NodePtr node) {
			NodePtr tmp;
			// Node has only a left child, it replaces the node
			if (node->left != nil) {
				tmp = node->left;
				updateParentsChildren(node, node->left);
				node->left->setParent(node->parent);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				return tmp;
			}
			else if (node->right != nil) {
				tmp = node->right;
				updateParentsChildren(node, node->right);
				node->right->setParent(node->parent);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				return tmp;
			}
			else	// node has no children, if black is replaced by tmp node for fixing properties
			{
				int nodeColor = node->color;
				NodePtr parentTmp = node->parent;
				updateParentsChildren(node, nil);
				_alloc.destroy(node);
				_alloc.deallocate(node, 1);
				if (nodeColor == BLACK)
					nil->setParent(parentTmp);
				return nil;
			}
		}

		// Main function for deleting & balancing the tree after deletion
		bool deleteHelper(const T& value) {
			NodePtr	upperNode;
			int		deletedNodeColor;

			NodePtr	node = searchTree(value);
			if (node == nil)
				return false;
			if (node->left == nil || node->right == nil)	// zero or one child
			{
				deletedNodeColor = node->color;
				upperNode = deleteParentNode(node);
			}
			else											// two children
			{
				NodePtr inOrderSuccessor = maximum(node->left);
				copySuccessor(node, inOrderSuccessor);
				deletedNodeColor = inOrderSuccessor->color;
				upperNode = deleteParentNode(inOrderSuccessor);
			}
			if (deletedNodeColor == BLACK)					// fix only if node was black
				fixRedBlackProperties(upperNode);
			return true;
		}

		// *** SEARCH ***

			NodePtr searchTreeHelper(NodePtr node, const T val) const {
				if (node == nil || (!_comp(val, node->value) && !_comp(node->value, val))) {
					return node;
				}
				if (_comp(val, node->value)) {
					return searchTreeHelper(node->left, val);
				}
				return searchTreeHelper(node->right, val);
			}

			// *** SUCCESSOR + PREDECESSOR ***

			NodePtr successor(NodePtr x) const {
				if (x->right != this->nil) {
					return minimum(x->right);
				}
				NodePtr y = x->parent;
				while (y != this->nil && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			NodePtr predecessor(NodePtr x) const {
				if (x->left != this->nil) {
					return maximum(x->left);
				}
				NodePtr y = x->parent;
				while (y != this->nil && x == y->left) {
					x = y;
					y = y->parent;
				}
				return y;
			}


			// *** MIN / MAX ***

			NodePtr minimum(NodePtr node) const {
				while (node->left != this->nil) {
					node = node->left;
				}
				return node;
			}

			NodePtr maximum(NodePtr node) const {
				while (node->right != this->nil && node->right != end) {
					node = node->right;
				}
				return node;
			}


		// *** DESTRUCTOR HELPERS ***

			void	deleteNodes(NodePtr node) {
				if (node != nil) {
					if (node->right != nil && node->right != end) {
						NodePtr tmpRight = node->right;
						deleteNodes(tmpRight);
					}
					if (node->left != nil && node->left != end) {
						NodePtr tmpLeft = node->left;
						deleteNodes(tmpLeft);
					}
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
				}
			}


		// *** PRINT ***

			void printHelper(NodePtr root, std::string indent, bool last) {
				if (root != this->nil && root != end) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} else {
						std::cout << "L----";
						indent += "|  ";
					}

					std::string sColor = root->color ? "BLACK" : "RED";
					if (sColor == "RED")
						std::cout << root->value << REDC << "(" << sColor << ")" << NC << std::endl;
					else
						std::cout << root->value << GRN << "(" << sColor << ")" << NC << std::endl;
					printHelper(root->left, indent, false);
					printHelper(root->right, indent, true);
				}
			}
  };
};
#endif
