/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:17:52 by eberkowi          #+#    #+#             */
/*   Updated: 2025/08/12 15:26:34 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() = default;
		MutantStack(const MutantStack &copy) = default;
		MutantStack& operator=(const MutantStack& copy) = default;
		~MutantStack() = default;

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator			begin() { return this->c.begin(); };
	const_iterator		cbegin() { return this->c.cbegin(); };

	iterator			end() { return this->c.end(); };
	const_iterator		cend() { return this->c.cend(); };

	reverse_iterator 		rbegin() { return this->c.rbegin(); };
	const_reverse_iterator	crbegin() { return this->c.crbegin(); };

	reverse_iterator		rend() { return this->c.rend(); };
	const_reverse_iterator	crend() { return this->c.crend(); };
};
