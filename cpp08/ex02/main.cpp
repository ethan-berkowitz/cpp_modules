/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberkowi <eberkowi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:48:43 by eberkowi          #+#    #+#             */
/*   Updated: 2025/09/02 13:36:42 by eberkowi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <stack>

int main()
{
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    std::cout << "mstack.top() = " << mstack.top() << std::endl;

    std::cout << "mstack.size() before pop = " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "mstack.size() after pop = " << mstack.size() << std::endl;

    mstack.push(30);
    mstack.push(40);
    mstack.push(50);
    mstack.push(60);

    // Forward iteration

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "iterator = ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Reverse iteration
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << "reverse iterator = ";
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;  // reverse_iterator moves backward when incremented
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);
}
