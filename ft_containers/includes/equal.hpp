/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:40:38 by erecuero          #+#    #+#             */
/*   Updated: 2022/04/13 17:45:16 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace	ft {

	// EQUALITY
	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2) {

				while (first1!=last1) {
					if (!(*first1 == *first2))
					return false;
					++first1; ++first2;
				}
				return true;
	};

	// PREDICATE
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred){

				while (first1!=last1) {
					if (!pred(*first1,*first2))
					return false;
					++first1; ++first2;
				}
				return true;
	};
}

#endif
