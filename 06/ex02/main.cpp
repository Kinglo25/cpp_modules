/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:16:04 by lmajerus          #+#    #+#             */
/*   Updated: 2024/10/03 09:50:33 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class D : public Base {
};

Base* generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		perror("Something went wrong");
		return (NULL);
	}
}

void identify(Base *p)
{
	std::cout << "Type *: ";
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Base::A";
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Base::B";
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Base::C";
	}
	else
	{
		std::cout << "Not a derived class from Base";
	}
	std::cout << std::endl;
}

void identify(Base &p)
{
	std::cout << "Type &: ";
	if (dynamic_cast<A *>(&p))
	{
		std::cout << "Base::A";
	}
	else if (dynamic_cast<B *>(&p))
	{
		std::cout << "Base::B";
	}
	else if (dynamic_cast<C *>(&p))
	{
		std::cout << "Base::C";
	}
	else
	{
		std::cout << "Not a derived class from Base";
	}
	std::cout << std::endl;
}

int	main(void)
{
	srand(time(NULL)); 
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test # " << i << std::endl;
		Base* test = generate();
		identify(test);
		identify(*test);
		delete (test);
	}
	Base* wrongClass = new D;
	identify(wrongClass);
	identify(*wrongClass);
}