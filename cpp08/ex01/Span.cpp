/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:21:34 by eberkowi          #+#    #+#             */
/*   Updated: 2025/05/12 12:29:37 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : N(0) {}

Span::Span(unsigned int N) : N(N) 
{
	this->vector.resize(N);
}

Span::Span(const Span &other) : N(other.N)
{
	this->vector.resize(N);
}

Span& Span::operator = (Span const &other)
{
	if (this != &other)
		N = other.N;
	return (*this);
}

Span::~Span(void) {}
