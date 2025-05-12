/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:17:52 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/12 12:24:44 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

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
};
