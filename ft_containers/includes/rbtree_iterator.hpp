#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

#include "rbtree_node.hpp"
#include "iterator_traits.hpp"

namespace ft {

	template<typename T>
		class rbtree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
			public:
				typedef T								value_type;
				typedef T&								reference;
				typedef T*								pointer;
				typedef bidirectional_iterator_tag 		iterator_category;
				typedef ptrdiff_t						difference_type;
				typedef ft::rbtree_iterator<T>			iterator;
				typedef typename ft::node<T>::basePtr	basePtr;
				typedef ft::node<T>*		 			NodePtr;

			protected:
				basePtr 									_baseNode;

			public:
				rbtree_iterator() : _baseNode() {};

				rbtree_iterator(NodePtr x) : _baseNode(x) {}

				rbtree_iterator(const iterator &rhs) : _baseNode(rhs.base()) {};

				~rbtree_iterator() {};

				basePtr 		base() const {
					return (this->_baseNode);
				}

				iterator& operator=(iterator const &rhs) {
					_baseNode = rhs.base();
					return *this;
				}

				reference	operator*() const	{
					return (this->_baseNode->value);
				}

				pointer	operator->() const {
					return &(this->_baseNode->value);
				}

				iterator&	operator++() {
					_baseNode = _Rb_tree_increment(_baseNode);
					return *this;
				}

				iterator	operator++(int) {
					iterator tmp = *this;
					_baseNode = _Rb_tree_increment(_baseNode);
					return tmp;
				}

				iterator&	operator--() {
					_baseNode = _Rb_tree_decrement(_baseNode);
					return *this;
				}

				iterator	operator--(int) {
					iterator tmp = *this;
					_baseNode = _Rb_tree_decrement(_baseNode);
					return tmp;
				}

				bool	operator==(const iterator& x) const {
					return _baseNode == x._baseNode;
				}

				bool	operator!=(const iterator& x) const {
					return _baseNode != x._baseNode;
				}

				operator rbtree_iterator<const T>() const {
					return (rbtree_iterator<const T>(_baseNode));
				}
		};

	template<typename T>
		class rbtree_const_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
			public:
				typedef T									value_type;
				typedef const T&							reference;
				typedef const T*							pointer;
				typedef bidirectional_iterator_tag			iterator_category;
				typedef ptrdiff_t							difference_type;
				typedef ft::rbtree_iterator<T>				iterator;
				typedef ft::rbtree_const_iterator<T>		const_iterator;
				typedef typename ft::node<T>::constBasePtr	basePtr;
				typedef const ft::node<T>*					NodePtr;

			protected:
				basePtr 									_baseNode;

			public:
				rbtree_const_iterator() : _baseNode() {};

				rbtree_const_iterator(NodePtr x) : _baseNode(x) {}

				rbtree_const_iterator(const iterator &rhs) : _baseNode(rhs.base()) {};

				~rbtree_const_iterator() {};

				basePtr 		base() const {
					return (this->_baseNode);
				}

				const_iterator& operator=(iterator const &rhs) {
					_baseNode = rhs.base();
					return *this;
				}

				reference	operator*() const	{
					return (this->_baseNode->value);
				}

				pointer	operator->() const {
					return &(this->_baseNode->value);
				}

				const_iterator&	operator++() {
					_baseNode = _Rb_tree_increment(_baseNode);
					return *this;
				}

				const_iterator	operator++(int) {
					const_iterator tmp = *this;
					_baseNode = _Rb_tree_increment(_baseNode);
					return tmp;
				}

				const_iterator&	operator--() {
					_baseNode = _Rb_tree_decrement(_baseNode);
					return *this;
				}

				const_iterator	operator--(int) {
					const_iterator tmp = *this;
					_baseNode = _Rb_tree_decrement(_baseNode);
					return tmp;
				}

				bool	operator==(const const_iterator& x) const {
					return _baseNode == x._baseNode;
				}

				bool	operator!=(const const_iterator& x) const {
					return _baseNode != x._baseNode;
				}
		};

	template <typename val>
		inline bool operator==(const rbtree_iterator<val>& x,
			const rbtree_const_iterator<val>& y)
			{ return x.base() == y.base(); }

	template <typename val>
		inline bool operator!=(const rbtree_iterator<val>& x,
			const rbtree_const_iterator<val>& y)
			{ return x.base() != y.base(); }

}

#endif
