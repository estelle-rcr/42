/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:50:55 by erecuero          #+#    #+#             */
/*   Updated: 2022/09/06 12:43:08 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "random_access_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace	ft {

template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T																			value_type;
			typedef Alloc 																		allocator_type;
			typedef typename allocator_type::reference 											reference;
			typedef typename allocator_type::const_reference 									const_reference;
			typedef typename allocator_type::pointer 											pointer;
			typedef typename allocator_type::const_pointer 										const_pointer;
			typedef random_access_iterator<value_type>											iterator;
			typedef random_access_iterator<const value_type>									const_iterator;
			typedef ft::reverse_iterator<iterator>												reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename allocator_type::size_type											size_type;

		private:
			pointer			_base;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

			bool 	updateCapacity(size_type n) {
				if (n > _capacity) {
					T *tmp = _alloc.allocate((n < _size * 2 ? _size * 2 : n));
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&tmp[i], _base[i]);
						_alloc.destroy(&_base[i]);
					}
					_alloc.deallocate(_base, _capacity);
					_capacity = (n < _size * 2 ? _size * 2 : n);
					_base = tmp;
					return true;
				}
				return false;
			}

		public:
		// *** CONSTRUCTORS ***
			// Empty container constructor (default constructor)
				explicit 	vector (const allocator_type& alloc = allocator_type()) :
					_alloc(alloc), _size(0), _capacity(0) {
					_base = _alloc.allocate(_capacity);
				};

			// Fill constructor
				explicit 	vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) : _alloc(alloc),  _size(n), _capacity(n) {
							_base = _alloc.allocate(_capacity);
							for (size_type i = 0; i < _size; i++)
								_alloc.construct(&_base[i], val);
						};

			// Range constructor
				template <class InputIterator>
					vector (InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type(),
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) :
								_alloc(alloc), _size(0), _capacity(0) {
						_size = ft::distance(first, last);
						_capacity = ft::distance(first, last);
						_base = _alloc.allocate(_capacity, 0);
							for (iterator it = begin(); first != last; it++, first++)
								_alloc.construct(&*it, *first);
					}

			// Copy constructor
				vector (const vector& x) : _base(0), _alloc(x._alloc), _size(0), _capacity(0) {
						assign(x.begin(), x.end());
					return ;
				}

		// *** DESTRUCTOR ***
			~vector() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_base + i);
				}
				_size = 0;
				_alloc.deallocate(_base, _capacity);
			}

		// *** ASSIGN OVERLOAD FUNCTION ***
			vector& operator= (const vector& x) {
				if (*this != x) {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_base[i]);
					_alloc.deallocate(_base, _capacity);
					_alloc = x._alloc;
					_size = x._size;
					if (x._capacity > _capacity)
						_capacity = x._capacity;
					_base = _alloc.allocate(_capacity, 0);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_base[i], x[i]);
				}
				return *this;
			}


		// *** ITERATORS ***
			iterator				begin() { return iterator(_base); }
			const_iterator 			begin() const { return const_iterator(_base); }
			iterator				end() { return iterator(_base + _size); }
			const_iterator 			end() const { return const_iterator(_base + _size); }
		 	reverse_iterator 		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
		 	reverse_iterator		rend()  { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const  { return const_reverse_iterator(begin()); }


		// *** CAPACITY ***
			size_type 	size() const {
				return (this->_size); }

			size_type	max_size() const {
				return (allocator_type().max_size());
			}

			void 		resize (size_type n, value_type val = value_type()) {
				updateCapacity(n);
				if (n < _size) {
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(&_base[i]);
					_size = n;
				}
				else {
					for (size_type i = _size; i < n; i++)
						_alloc.construct(&_base[i], val);
					_size = n;
				}
			}

			size_type	capacity() const {
				return (this->_capacity); }

			bool 		empty() const {
				return (this->_size == 0);
			};

			void 		reserve (size_type n)  throw(std::length_error) {
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > _capacity) {
					T *tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&tmp[i], _base[i]);
						_alloc.destroy(&_base[i]);
					}
					_alloc.deallocate(_base, _capacity);
					_capacity = n;
					_base = tmp;
				}

			}

		// *** ELEMENT ACCESS ***
		    reference operator[](size_type n) {
				return *(this->_base + n);
			};

			const_reference operator[](size_type n) const {
				return *(this->_base + n);
			};

			reference at(size_type n) throw(std::out_of_range) {
				if (n >= this->_size)
					throw std::out_of_range("vector::at");
				return *(this->_base + n);
			};

			const_reference at(size_type n) const throw(std::out_of_range) {
				if (n >= this->_size)
					throw std::out_of_range("vector::at");
				return *(this->_base + n);
			};

			reference front() {
				return *(this->_base);
			};

			const_reference front() const {
				return *(this->_base);
			};

			reference back() {
				return *(this->_base + (this->_size - 1));
			};

			const_reference back() const {
				return *(this->_base + (this->_size - 1));
			};

		// *** MODIFIERS ***

			template <class InputIterator>
 				void	assign (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
					erase(begin(), end());
					insert(begin(), first, last);
				};

			void		assign (size_type n, const value_type& val) {
				erase(begin(), end());
				insert(begin(), n, val);
			};

			void		push_back (const value_type& val) {
				insert(end(), 1, val);
			};

			void 		pop_back() {
				erase(end() - 1);
			};

			iterator	insert(iterator position, const value_type& val) {
				size_type dist = position - begin();
				insert(position, 1, val);
				return (begin() + dist);
			};

			void		insert(iterator position, size_type n, const value_type& val) {
				if (n <= 0)
					return ;
				size_type start = ft::distance(begin(), position);
				size_type i = size();
				updateCapacity(_size + n);
				while (i > 0 && --i >= start) {
					_alloc.construct(_base + i + n, *(_base + i));
					_alloc.destroy(_base + i);
				}
				size_type j = 0;
				while (j < n) {
					_alloc.construct(_base + start, val);
					start++;
					j++;
				}
				_size += n;
			};

			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
				{
					size_type start = ft::distance(begin(), position);
					size_type i = size();
					size_type n = ft::distance(first, last);
					updateCapacity(_size + n);
					while (i > 0 && --i >= start) {
						_alloc.construct(_base + i + n, *(_base + i));
						_alloc.destroy(_base + i);
					}
					size_type j = 0;
					while (j < n) {
						_alloc.construct(_base + start, *(first));
						first++;
						start++;
						j++;
					}
					_size += n;
				};

			iterator 	erase(iterator position) {
				if (_size) {
					size_type start = ft::distance (begin(), position);
					for (iterator it = position + 1; it != end(); it++) {
						_alloc.destroy(_base + start);
						_alloc.construct(_base + start, *it);
						start++;
					}
					_alloc.destroy(_base + start);
					_size--;
				}
				return (position);
			};

			iterator 	erase(iterator first, iterator last) {
				if (_size) {
					size_type start = ft::distance (begin(), first);
					size_type n = ft::distance(first, last);
					for (iterator it = last; it != end(); it++) {
						_alloc.destroy(_base + start);
						_alloc.construct(_base + start, *it);
						start++;
					}
					while (start < _size) {
						_alloc.destroy(_base + start);
						start++;
					}
					_size -= n;
				}
				return (first);
			};

			void 		swap(vector& x) {
				pointer			tmpArray;
				allocator_type	tmpAlloc;
				size_type		tmpSize;
				size_type		tmpCapacity;
				tmpArray = _base;
				tmpAlloc = _alloc;
				tmpSize = _size;
				tmpCapacity = _capacity;
				_base = x._base;
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._capacity;
				x._base = tmpArray;
				x._alloc = tmpAlloc;
				x._size = tmpSize;
				x._capacity = tmpCapacity;
			};

			void 		clear() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_base[i]);
				_size = 0;
			};


			// *** ALLOCATOR ***

			allocator_type get_allocator() const {
				return _alloc;
			};
	};


	// *** NON-MEMBER FUNCTION OVERLOADS ***
	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		};

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return !(lhs == rhs);
		};

	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		};

	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return !(lhs > rhs);
		};

	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return rhs < lhs;
		};

	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
			return !(lhs < rhs);
		};

	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
			x.swap(y);
		};

};

#endif
