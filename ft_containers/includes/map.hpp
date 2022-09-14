/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:16:28 by erecuero          #+#    #+#             */
/*   Updated: 2022/09/06 12:38:24 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <iostream>
#include <memory>
#include "rbtree.hpp"
#include "pair.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"

namespace	ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
		class map {
			public:
				typedef Key																			key_type;
				typedef T																			mapped_type;
				typedef	ft::pair<const Key, T>														value_type;
				typedef Compare																		key_compare;
				typedef Alloc																		allocator_type;
				typedef typename allocator_type::reference											reference;
				typedef	typename allocator_type::const_reference									const_reference;
				typedef	typename allocator_type::pointer											pointer;
				typedef	typename allocator_type::const_pointer										const_pointer;
				typedef ft::rbtree_iterator<value_type>												iterator;
				typedef ft::rbtree_const_iterator<value_type>										const_iterator;
				typedef ft::reverse_iterator<iterator>												reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;
				typedef	typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
				typedef typename allocator_type::size_type											size_type;


				class value_compare : public std::binary_function<value_type,value_type,bool> {
					friend class map;

					protected:
						Compare comp;
						value_compare (Compare c) : comp(c) {}

					public:

						bool operator() (const value_type& x, const value_type& y) const {
							return comp(x.first, y.first);
					}

				};

		protected:
			typedef ft::RBTree< value_type, value_compare, allocator_type > baseTree;
			mapped_type 	_value;
			size_type		_capacity;
			allocator_type	_alloc;
			key_compare		_comp;
			baseTree		_base;

		public:
		// *** CONSTRUCTORS ***

			// Empty container constructor (default constructor)
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _value(T()), _alloc(alloc), _comp(comp), _base(comp) {};

			// Range constructor
			template <class InputIterator>
				map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _value(T()), _alloc(alloc), _comp(comp), _base(comp) {
					insert(first, last);
				};

			// Copy constructor
			map(const map<Key,T, Compare, Alloc>& x)  : _value(T()), _alloc(x._alloc), _comp(x._comp), _base(x._comp) {
					*this = x;
				};

		// *** DESTRUCTOR ***

			~map() {};

		// *** ASSIGN OVERLOAD FUNCTION ***

			map& operator=(const map& x) {
				if (*this != x) {
					this->clear();
					this->insert(x.begin(), x.end());
				}
				return *this;
			};


		// *** ITERATORS ***

			iterator				begin() { return iterator(_base.getBegin()); }
			const_iterator 			begin() const { return const_iterator(_base.getBegin()); }
			iterator				end() { return iterator(_base.getEndSuccessor()); }
			const_iterator 			end() const { return const_iterator(_base.getEndSuccessor()); }
			reverse_iterator 		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator		rend()  { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const  { return const_reverse_iterator(begin()); }


		// *** CAPACITY ***

			bool empty() const { return (_base.getSize() == 0); };
			size_type size() const { return (_base.getSize()); };
			size_type max_size() const { return _base.maxSize(); };


		// *** ELEMENT ACCESS ***

			mapped_type& operator[](const key_type& k) {
				if (_base.searchTree(ft::make_pair<key_type, mapped_type>(k, _value)) == _base.getNil())
					_base.insert(ft::make_pair<key_type, mapped_type>(k, _value));
				return (_base.searchTree(ft::make_pair<key_type, mapped_type>(k, _value))->value.second);
			};

		// *** MODIFIERS ***

			// single element (1)
			pair<iterator,bool> insert(const value_type& val) {
				size_type previousSize = _base.getSize();
				_base.insert(val);
				return (ft::make_pair(iterator(_base.searchTree(val)),
					(previousSize != _base.getSize() ? true : false)));
			};

			// with hint (2)
			iterator	insert(iterator position, const value_type& val) {
				(void)position;
				return (iterator(_base.insert(val)));
			};

			// range (3)
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				for (InputIterator it = first; it != last; it++)
					_base.insert(ft::make_pair(it->first, it->second));
			};

			// position
			void	erase(iterator position) {
				_base.deleteNode(ft::make_pair(position->first, position->second));
			};

			// key_type
			size_type	erase(const key_type& k) {
				return (_base.deleteNode(ft::make_pair(k,mapped_type())));
			}

			// iterators
			void	erase(iterator first, iterator last) {
				iterator tmp;
				for (iterator it = first; it != last;) {
					tmp = it;
					it++;
					_base.deleteNode(ft::make_pair(tmp->first, tmp->second));
				}
			}

			void	swap(map& x) {
				_base.swap(x._base);
			};

			void	clear() {
				erase(begin(), end());
			};

		// *** OBSERVERS ***
			key_compare	key_comp() const { return key_compare(); };
			value_compare	value_comp() const { return value_compare(_comp); };


		// *** OPERATIONS ***
			iterator		find(const key_type& k) {
				return (iterator(_base.searchTree(ft::make_pair(k,mapped_type()))));
			};

			const_iterator	find(const key_type& k) const {
				return (const_iterator(_base.searchTree(ft::make_pair(k,mapped_type()))));
			};

			size_type		count(const key_type& k) const {
				return(_base.isInTree(ft::make_pair(k,mapped_type())));
			};

			iterator 		lower_bound(const key_type& k) {
				iterator it = _base.searchTree(ft::make_pair(k,mapped_type()));
				if (it == _base.getNil()) {
					iterator ite = iterator(_base.getEndSuccessor());
					for (iterator itb = _base.getBegin(); itb != ite; itb++) {
						if (itb->first > k)
							return itb;
					}
					return ite;
				}
				return it;
			};

			const_iterator	lower_bound(const key_type& k) const {
				const_iterator it = _base.searchTree(ft::make_pair(k,mapped_type()));
				if (it == _base.getNil()) {
					const_iterator ite = iterator(_base.getEndSuccessor());
					for (iterator itb = _base.getBegin(); itb != ite; itb++) {
						if (itb->first > k)
							return itb;
					}
					return ite;
				}
				return it;
			};

			iterator 		upper_bound(const key_type& k) {
				iterator ite = iterator(_base.getEndSuccessor());
				for (iterator itb = _base.getBegin(); itb != ite; itb++) {
					if (itb->first > k)
						return itb;
				}
				return ite;
			};

			const_iterator	upper_bound(const key_type& k) const {
				const_iterator ite = iterator(_base.getEndSuccessor());
				for (const_iterator itb = _base.getBegin(); itb != ite; itb++) {
					if (itb->first > k)
						return itb;
				}
				return ite;
			};

			pair<iterator,iterator>				equal_range(const key_type& k) {
				return(ft::make_pair(lower_bound(k), upper_bound(k)));
			};

			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const {
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			};


		// *** ALLOCATOR ***

			allocator_type	get_allocator() const {
				return _alloc;
			};

		};

	// *** NON-MEMBER FUNCTIONS ***

	template <class Key, class T, class Compare, class Alloc>
		bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		};

	template <class Key, class T, class Compare, class Alloc>
		bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			return !(lhs == rhs);
		};

	template <class Key, class T, class Compare, class Alloc>
		bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		};

	template <class Key, class T, class Compare, class Alloc>
		bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			return !(lhs > rhs);
		};

	template <class Key, class T, class Compare, class Alloc>
		bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
			return rhs < lhs;
		};

	template <class Key, class T, class Compare, class Alloc>
		bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )  {
			return !(lhs < rhs);
		};

	template <class Key, class T, class Compare, class Alloc>
  		void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
			x.swap(y);
	};
}

#endif
