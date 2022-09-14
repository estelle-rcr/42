/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:51:25 by erecuero          #+#    #+#             */
/*   Updated: 2022/09/05 15:44:51 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace	ft {

	template <class Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category, Iterator> {

		protected:
			Iterator 														_current;
			typedef iterator_traits<Iterator>                				_traits_type;

		public:
			typedef Iterator 												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

		// *** CONSTRUCTORS ***
				reverse_iterator() : _current(0) {};
				explicit reverse_iterator (iterator_type ite) : _current(ite) {};
				reverse_iterator(const reverse_iterator& other) : _current(other._current) { }
				template <typename Iter>
					reverse_iterator (const reverse_iterator<Iter>& other) : _current(other.base()) {};
				
				~reverse_iterator() {};

		// *** MEMBER FUNCTIONS ***
			reverse_iterator &operator=(const reverse_iterator& src) {
				if (this == &src)
					return (*this);
				this->_current = src._current;
				return (*this);
			}

			iterator_type 		base() const {
				return (this->_current);
			}

			reference			operator*() const {
				Iterator	tmp = this->_current;
				return (*--tmp);
			};

			pointer 			operator->() const { 
				Iterator	tmp = this->_current;
				return &(operator*()); 
			}

			reverse_iterator& 	operator++() {
				--this->_current;
				return (*this);
			};

			reverse_iterator  	operator++(int) {
				reverse_iterator tmp = *this;
				--(this->_current);
				return (tmp);
			};

			reverse_iterator& 	operator--() {
				++this->_current;
				return (*this);
			};

			reverse_iterator  	operator--(int) {
				reverse_iterator tmp = *this;
				++(this->_current);
				return tmp;
			};

			reverse_iterator 	operator+ (difference_type n) const {
				return (reverse_iterator(this->_current - n));
			};

			reverse_iterator& 	operator+= (difference_type n) {
				this->_current -= n;
				return (*this);
			};

			reverse_iterator 	operator- (difference_type n) const {
				return (reverse_iterator(this->_current + n));
			};

			reverse_iterator& 	operator-= (difference_type n) {
				this->_current += n;
				return (*this);
			};

			reference 			operator[] (difference_type n) const {
				return *(*this + n);
			}

			operator reverse_iterator<const Iterator> () const {
				return (reverse_iterator<const Iterator>(this->_current));
			}

	};

	// *** NON MEMBER FUNCTIONS - RELATIONAL OPERATORS ***
	template <typename IteratorL, typename IteratorR>
		bool operator== (const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						return lhs.base() == rhs.base();
					};

	template <typename IteratorL, typename IteratorR>
		bool operator!= (const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						return lhs.base() != rhs.base();
					};

	template <typename IteratorL, typename IteratorR>
		bool operator<  (const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						return rhs.base() < lhs.base();
					};

	template <typename IteratorL, typename IteratorR>
		bool operator<= (const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						 return rhs.base() <= lhs.base();
					};

	template <typename IteratorL, typename IteratorR>
		bool operator>  (const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						 return rhs.base() > lhs.base();
					};

	template <typename IteratorL, typename IteratorR>
		bool operator>= (const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						 return rhs.base() >= lhs.base();
					};

	// *** NON MEMBER FUNCTIONS - NON RELATIONAL OPERATORS ***

	template <typename IteratorL, typename IteratorR>
		typename reverse_iterator<IteratorL>::difference_type
			operator-(const reverse_iterator<IteratorL>& lhs,
					const reverse_iterator<IteratorR>& rhs) {
						return ( rhs.base() - lhs.base() );
					};

	template <class Iterator>
		reverse_iterator<Iterator>
			operator+(typename reverse_iterator<Iterator>::difference_type n,
					const reverse_iterator<Iterator>& rev_it)
		{ return reverse_iterator<Iterator>(rev_it.base() - n); }

};

#endif
