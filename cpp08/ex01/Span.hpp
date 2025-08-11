/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:17:52 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/11 13:20:19 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Span
{
	public:

		unsigned int N;
		std::vector<int> vector;

		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator = (Span const &other);
		~Span();

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void print();

		template <typename T>
		void addRangeOfIterators(T begin, T end) {
			if (distance(begin, end) > N - (unsigned int)vector.size()) {
				throw SpanCannotFitRange();
			}
			vector.insert(vector.end(), begin, end);
		}

		class SpanIsFilled : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return ("Span is filled");
				}
		};

		class SpanCannotFitRange : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return ("Span is too filled to fit the given range");
				}
		};

		class NoSpanFound : public std::exception {
			public:
				virtual const char *what() const noexcept {
					return ("No span can be found");
				}
		};
};
