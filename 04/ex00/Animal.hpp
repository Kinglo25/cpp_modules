/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:15:32 by lmajerus          #+#    #+#             */
/*   Updated: 2024/06/28 16:07:39 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& cpy);
	virtual ~Animal();

	Animal& operator=(const Animal& rhs);

	std::string	get_type() const;
	void		set_type(std::string const type);

	virtual void	makeSound() const;


protected:
	std::string	type_;
};

#endif