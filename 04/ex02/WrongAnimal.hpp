/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:46:34 by lmajerus          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:32 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& cpy);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& rhs);

	std::string	get_type() const;
	void		set_type(std::string const type);

	void	makeSound() const;


protected:
	std::string	_type;
};

#endif