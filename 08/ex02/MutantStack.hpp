/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:52 by lmajerus          #+#    #+#             */
/*   Updated: 2024/11/07 09:17:51 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
public:
	// Constructors
	MutantStack() : MutantStack<T, Container>::stack() {};
	MutantStack(const MutantStack<T, Container>& other) : MutantStack<T, Container>::stack(other) {};

	// Assignment operator overload
	MutantStack<T, Container>& operator=(const MutantStack<T, Container>& rhs)
	{
		if (this != &rhs)
			this->MutantStack<T, Container>::stack::operator=(rhs);
		return *this;
	}

	// Destructor
	virtual ~MutantStack() {};

	typedef typename Container::iterator				iterator;
	typedef typename Container::reverse_iterator		reverse_iterator;

	iterator			begin() { return this->c.begin(); };
	iterator			end() { return this->c.end(); };
	reverse_iterator	rbegin() { return this->c.rbegin(); };
	reverse_iterator	rend() { return this->c.rend(); };
};