/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:45:13 by lmajerus          #+#    #+#             */
/*   Updated: 2024/11/07 09:04:22 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span a = Span(5);
		for (size_t i = 0; i < 6; i++)
		{
			try
			{
				a.addNumber(i);
			}
			catch (std::exception &e)
			{
				std::cerr << std::endl << e.what() << std::endl;
			}
		}
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl;
	}
	std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;
	{
		Span a = Span(10);
		a.addRandomNumber(10);
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl << std::endl;
	}
	std::cout << std::endl << "---------------------------------------------------------------" << std::endl << std::endl;
	{
		Span a = Span(0);
		try
		{
			std::cout << a.shortestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
