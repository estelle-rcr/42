/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:40:55 by erecuero          #+#    #+#             */
/*   Updated: 2022/04/13 18:11:49 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace	ft {

	template <bool, typename T = void>
		struct enable_if {};

	template <typename T>
		struct enable_if<true, T> {
 		 	typedef T type;
	};
}

#endif
