/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:16:01 by erecuero          #+#    #+#             */
/*   Updated: 2022/09/02 12:19:03 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace	ft {

	template <class T1, class T2>
		struct pair {
			T1 first;
			T2 second;

			// Default constructor
			pair() : first(T1()), second(T2()) {};

			// Initialisation constructor
			pair(const T1& x, const T2& y) : first(x), second(y) {};

			// Copy constructor
			template<class U, class V>
				pair(const pair< U, V>& pr) : first(pr.first), second(pr.second) {};

			pair<T1, T2>& operator=(const pair<T1, T2>& pr) {
				if (*this != pr) {
					first = pr.first;
					second = pr.second;
				}
				return *this;
			};
		};

	template <class T1, class T2>
		bool operator== (const pair< T1, T2>& lhs, const pair< T1, T2>& rhs) {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		};

	template <class T1, class T2>
		bool operator!= (const pair< T1, T2>& lhs, const pair< T1, T2>& rhs) {
			return !(lhs == rhs);
		};

	template <class T1, class T2>
		bool operator<  (const pair< T1, T2>& lhs, const pair< T1, T2>& rhs) {
			return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
		};

	template <class T1, class T2>
		bool operator<= (const pair< T1, T2>& lhs, const pair< T1, T2>& rhs) {
			return !(rhs < lhs);
		};

	template <class T1, class T2>
		bool operator>  (const pair< T1, T2>& lhs, const pair< T1, T2>& rhs) {
			return (rhs < lhs);
		};
	template <class T1, class T2>
		bool operator>= (const pair< T1, T2>& lhs, const pair< T1, T2>& rhs) {
			return !(lhs < rhs);
		};

	template <class T1, class T2>
		ft::pair< T1, T2> make_pair(T1 x, T2 y) {
			return (ft::pair< T1, T2>(x, y));
		};

	template <typename V, typename U>
		std::ostream &operator<<(std::ostream &os, const ft::pair<V, U> &pair)
		{
			os << "[ " << pair.first << " : " << pair.second << " ]";
			return os;
		}
}


#endif
