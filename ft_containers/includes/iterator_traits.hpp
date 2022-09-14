/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:52:13 by erecuero          #+#    #+#             */
/*   Updated: 2022/04/15 16:04:41 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include "iterator.hpp"
#include "random_access_iterator.hpp"

namespace	ft {

	template <class Iterator>
		struct iterator_traits {
				typedef typename	Iterator::difference_type 	difference_type;
				typedef typename	Iterator::value_type 		value_type;
				typedef typename	Iterator::pointer 			pointer;
				typedef typename	Iterator::reference 		reference;
				typedef typename	Iterator::iterator_category	iterator_category;
		};

	template <class T>
		struct iterator_traits<T*> {
					typedef	ptrdiff_t						difference_type;
					typedef	T								value_type;
					typedef	T*								pointer;
					typedef	T&								reference;
					typedef	ft::random_access_iterator_tag	iterator_category;
		};

	template <class T>
		struct iterator_traits<const T*> {
				typedef	ptrdiff_t						difference_type;
				typedef	T								value_type;
				typedef	const T*						pointer;
				typedef	const T&						reference;
				typedef	ft::random_access_iterator_tag	iterator_category;
		};


	template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
			distance(InputIterator first, InputIterator last) {

				typename ft::iterator_traits<InputIterator>::difference_type  n = 0;
				while (first != last) {
					first++;
					n++;
				}
				return (n);
			}

	template<typename T>
		typename ft::iterator_traits< ft::random_access_iterator<T> >::difference_type distance(ft::random_access_iterator<T> first, ft::random_access_iterator<T> last) {
			return last - first;
		}

  };

#endif
