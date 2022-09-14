/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:41:28 by erecuero          #+#    #+#             */
/*   Updated: 2022/09/02 20:27:34 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace	ft {

	template <class T, class Container = ft::vector<T> >
		class stack {
			public:
				typedef T									value_type;
				typedef Container							container_type;
				typedef typename Container::size_type		size_type;

			protected:
				Container	c;

			public:
				explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {};

				bool empty() const {
					return (c.empty());
				};

				size_type size() const {
					return (c.size());
				};

				value_type& top() {
					return (c.back());
				};

				const value_type& top() const {
					return (c.back());
				};

				void push (const value_type& val) {
					if (c.size() < c.max_size())
						c.push_back(val);
				};

				void pop() {
					c.pop_back();
				};

				template <class Tp, class Seq>
					friend bool operator== (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs);

				template <class Tp, class Seq>
					friend bool operator<  (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs);

		};

	template <class Tp, class Seq>
		bool operator== (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs) {
			return (lhs.c == rhs.c);
		};


	template <class Tp, class Seq>
		bool operator!= (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs) {
			return !(lhs == rhs);
	};

	template <class Tp, class Seq>
  		bool operator<  (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs) {
			return (lhs.c < rhs.c);
		  };


	template <class Tp, class Seq>
		bool operator<= (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs) {
			return !(lhs > rhs);
		};

	template <class Tp, class Seq>
		bool operator>  (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs) {
			return rhs < lhs;
		};

	template <class Tp, class Seq>
		bool operator>= (const stack< Tp, Seq>& lhs, const stack< Tp, Seq>& rhs) {
			return !(lhs < rhs);
		};

}

#endif
