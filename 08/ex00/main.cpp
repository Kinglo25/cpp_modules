/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:12:56 by lmajerus          #+#    #+#             */
/*   Updated: 2024/11/07 08:28:03 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int> test;
	std::list<int>::iterator it;
	for (int i = 1; i <= 19; i++)
		test.push_back(i);
	try
	{
		it = easyfind(test, 19);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it = easyfind(test, 42);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}