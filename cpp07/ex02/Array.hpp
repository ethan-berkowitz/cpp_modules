/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:50:27 by mroux             #+#    #+#             */
/*   Updated: 2025/05/08 12:03:32 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <string>

template <class T>
class Array
{
	public:

		Array();
		Array(unsigned int i);
		~Array();
		Array(Array<T> const&);
		Array<T>&		operator=(Array<T> const&);
		T&				operator[](unsigned int i);
		void			display(std::ostream& stream) const;
		unsigned int	size() const;

	private:

		T				*_arr;
		unsigned int	_size;
};

// Overload operators for <<
template <class T>
std::ostream&	operator<<(std::ostream& stream, Array<T>const& cl);

// Construction with no parameter
template <class T>
Array<T>::Array()
{
	_arr = new T[0];
	_size = 0;
}

// Construction with an unsigned int n as a parameter
template <class T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = T();
}

// Destructor
template <class T>
Array<T>::~Array()
{
	delete[] _arr;
}

// Copy constructor
template <class T>
Array<T>::Array(Array const& other)
{
	_arr = NULL;
	operator=(other);
}

// Assignment operator =
template <class T>
Array<T>&	Array<T>::operator=(Array<T> const& other)
{
	if (this == &other)
		return (*this);
	if (_arr != NULL)
		delete[] _arr;
	_size = other._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
	return (*this);
}

// Subscript operator []
template <class T>
T&			Array<T>::operator[](unsigned int i)
{
	std::cout << i << std::endl;
	if (i >= _size)
		throw std::exception();
	return _arr[i];
}

//Size function
template <class T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

//Display function for testing
template <class T>
void		Array<T>::display(std::ostream& stream) const
{
	unsigned int i = 0;
	if (_size == 0)
		return;
	for (i = 0; i < _size - 1; i++)
		stream << _arr[i] << " - ";
	if (i == _size - 1)
		stream << _arr[i];
}

//Operator << for output stream for testing
template <class T>
std::ostream&	operator<<(std::ostream& stream, Array<T>const& array)
{
	array.display(stream);
	return (stream);
}

#endif