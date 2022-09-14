#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef>
#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace	ft {

	template <typename T>
		class	random_access_iterator : public iterator<ft::random_access_iterator_tag, T> {

			public:
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type       difference_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer               pointer;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference             reference;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category     iterator_category;

			protected:
				pointer _current;

			public:
				// *** CONSTRUCTORS ***
				random_access_iterator(void) : _current(0) {};
				random_access_iterator(pointer ite) : _current(ite) {};
				random_access_iterator(const random_access_iterator& other) : _current(other._current) {};
				~random_access_iterator() {};

				// *** MEMBER FUNCTIONS ***
				random_access_iterator &operator=(const random_access_iterator& src) {
					if (this == &src)
						return (*this);
					this->_current = src._current;
					return (*this);
				}

				pointer	base() const {
					return (this->_current);
				}

				reference				operator*() const {
					pointer tmp = this->_current;
					return (*tmp);
				}

				pointer 				operator->() const { 
					return &(operator*()); 
				}

				random_access_iterator& operator++(void) {
					this->_current++;
					return (*this);
				}

				random_access_iterator 	operator++(int) {
					random_access_iterator tmp = *this;
					++(this->_current);
					return (tmp);
				}

				random_access_iterator& operator--(void) {
					this->_current--;
					return (*this);
				}

				random_access_iterator 	operator--(int) {
					random_access_iterator tmp = *this;
					--(this->_current);
					return (tmp);
				}

				random_access_iterator 	operator+(difference_type n) const {
					return (random_access_iterator(this->_current + n));
				}

				random_access_iterator&	operator+=(difference_type n) {
					this->_current += n;
					return (*this);
				}

				random_access_iterator 	operator-(difference_type n) const {
					return (random_access_iterator(this->_current - n));
				}

				random_access_iterator&	operator-=(difference_type n) {
					this->_current -= n;
					return (*this);
				}

				reference				operator[](difference_type n) const {
					return *(*this + n);
				}

				operator random_access_iterator<const T>() const {
					return (random_access_iterator<const T>(_current));
				}
		};

		template <typename IteratorL, typename IteratorR>
			bool operator== (const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return lhs.base() == rhs.base();
						};

		template <typename IteratorL, typename IteratorR>
			bool operator!= (const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return lhs.base() != rhs.base();
						};

		template <typename IteratorL, typename IteratorR>
			bool operator<  (const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return rhs.base() > lhs.base();
						};

		template <typename IteratorL, typename IteratorR>
			bool operator<= (const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return rhs.base() >= lhs.base();
						};

		template <typename IteratorL, typename IteratorR>
			bool operator>  (const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return rhs.base() < lhs.base();
						};

		template <typename IteratorL, typename IteratorR>
			bool operator>= (const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return rhs.base() <= lhs.base();
						};

		template <typename IteratorL, typename IteratorR>
			inline typename random_access_iterator<IteratorL>::difference_type
				operator-(const random_access_iterator<IteratorL>& lhs,
						const random_access_iterator<IteratorR>& rhs) {
							return ( lhs.base() - rhs.base() );
						};

		template <class Iterator>
			random_access_iterator<Iterator>
				operator+(	typename random_access_iterator<Iterator>::difference_type n,
						const random_access_iterator<Iterator>& rhs)
			{ return random_access_iterator<Iterator>(rhs.base() + n); }

}

#endif