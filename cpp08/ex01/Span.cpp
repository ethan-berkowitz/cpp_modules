/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:21:34 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/14 12:15:04 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : N(0) {}

Span::Span(unsigned int N) : N(N) 
{
	this->vector.reserve(N);
}

Span::Span(const Span &other) : N(other.N)
{
	this->vector.reserve(N);
}

Span& Span::operator = (Span const &other)
{
	if (this != &other)
		N = other.N;
	return (*this);
}

Span::~Span(void) {}

void Span::addNumber(int num)
{
	if (vector.size() == N)
		throw SpanIsFilled();
	vector.push_back(num);
}

int Span::shortestSpan()
{
	if (vector.size() <= 1)
		throw NoSpanFound();
	std::vector<int> temp = vector;
	std::sort(temp.begin(), temp.end());
	int result = temp[1] - temp[0];
	for (int i = 1; i < (int)temp.size() - 1; i++)
	{
		if (temp[i + 1] - temp[i] < result)
			result = temp[i + 1] - temp[i];
	}
	return (result);
}

int Span::longestSpan()
{
	if (vector.size() <= 1)
		throw NoSpanFound();
	std::vector<int> temp = vector;
	std::sort(temp.begin(), temp.end());
	int result = temp.back() - temp.front();
	return (result);
}

void Span::print()
{
	std::cout << "vector = [";
    for (size_t i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i];
        if (i != vector.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" <<std::endl;
}

