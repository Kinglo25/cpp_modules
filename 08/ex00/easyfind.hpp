/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:12:50 by lmajerus          #+#    #+#             */
/*   Updated: 2024/11/07 08:25:10 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <iostream>

struct NotInContainerException : public std::exception
{
	const char* what() const throw()
	{
		return ("Number not in the container");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int x)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), x);
	if (it == container.end())
		throw NotInContainerException();
	return (it);		
}

#endif