/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:39:56 by erecuero          #+#    #+#             */
/*   Updated: 2022/04/14 15:50:48 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace	ft {

	template <typename T, bool val = false >
	struct is_integral  {
		const static bool value = val;
	};

	template<> struct is_integral<unsigned char> : public is_integral<unsigned char, true> {};
	template<> struct is_integral<unsigned short> : public is_integral<unsigned short, true> {};
	template<> struct is_integral<unsigned int> : public is_integral<unsigned int, true> {};
	template<> struct is_integral<unsigned long> : public is_integral<unsigned long, true> {};
	template<> struct is_integral<signed char> : public is_integral<signed char, true> {};
	template<> struct is_integral<short> : public is_integral<short, true> {};
	template<> struct is_integral<long> : public is_integral<long, true> {};
	template<> struct is_integral<char> : public is_integral<char, true> {};
	template<> struct is_integral<bool>: public is_integral<bool, true> {};
	template<> struct is_integral<int>: public is_integral<int, true> {};

}

#endif
