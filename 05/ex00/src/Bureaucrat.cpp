/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:33:12 by lmajerus          #+#    #+#             */
/*   Updated: 2024/07/22 17:31:56 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ----------------------------- Constructors ------------------------------ //
Bureaucrat::Bureaucrat() : _name("John"), _grade(150)
{
	_BUREAUCRAT_AUTO(32, "Default Constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat& c) : _name(c._name), _grade(c._grade)
{
	_BUREAUCRAT_AUTO(32, "Copy Constructor");
	*this = c;
}

Bureaucrat::Bureaucrat(std::string in__name, int in__grade) : _name(in__name), _grade(150)
{
	_BUREAUCRAT_AUTO(32, "Fields Constructor");
	set__grade(in__grade);
}

// ------------------------------ Destructor ------------------------------- //
Bureaucrat::~Bureaucrat()
{
	_BUREAUCRAT_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& c)
{
	_BUREAUCRAT_AUTO(32, "Copy Assignement Operator");
	// _name = c._name;
	_grade = c._grade;
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &in)
{
	return (o << in.get__name() << ", bureaucrat grade " << in.get__grade());
}

// --------------------------- Getters && Setters -------------------------- //
const std::string Bureaucrat::get__name() const{ return _name; }
// void Bureaucrat::set__name(const std::string input){ _name = input; }

int Bureaucrat::get__grade() const{ return _grade; }
void Bureaucrat::set__grade(int input)
{
	if (input > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (input < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade = input;
}

// --------------------------------- Methods ------------------------------- //

	void Bureaucrat::increment_grade() { set__grade(_grade - 1); }
	void Bureaucrat::decrement_grade() { set__grade(_grade + 1); }

