/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:01:47 by lmajerus          #+#    #+#             */
/*   Updated: 2024/10/08 15:31:04 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tempolado.hpp"
#include <iostream>

int	main()
{

	{
	float	a = 21.445f;
	float	b = 42.445f;

	std::cout << "The max of a: " << a << " and b: " << b << " is:" <<
	"\t" << max(a, b) << std::endl;

	std::cout << "The min of a: " << a << " and b: " << b << " is:" <<
	"\t" << min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "before:\n\ta: " << a << "\n\tb: " << b << std::endl;
	swap(a, b);
	std::cout << "after:\n\ta: " << a << "\n\tb: " << b << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------------------------" << std::endl << std::endl;

	{
	std::string	a = "String A";
	std::string b = "String B";

	std::cout << "The max of a: " << a << " and b: " << b << " is:" <<
	"\t" << ::max(a, b) << std::endl;

	std::cout << "The min of a: " << a << " and b: " << b << " is:" <<
	"\t" << ::min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "before:\n\ta: " << a << "\n\tb: " << b << std::endl;
	::swap(a, b);
	std::cout << "after:\n\ta: " << a << "\n\tb: " << b << std::endl;
	}
	std::cout << std::endl;
	
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return (0);
	return (0);
}