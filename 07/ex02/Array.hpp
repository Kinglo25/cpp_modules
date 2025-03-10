/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:13:24 by lmajerus          #+#    #+#             */
/*   Updated: 2024/10/08 17:20:55 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <chrono>
#include <thread>

template <typename T>
class Array
{
public:
	Array() : _size(0)
	{
		std::cout << "Default constructor called" << std::endl;
		this->_array = new T[_size];
	}
	Array(unsigned int n) : _size(n)
	{
		std::cout << "Sized constructor called" << std::endl;
		this->_array = new T[_size];
	}
	Array(const Array &cpy) : _size(cpy.size())
	{
		std::cout << "Copy Constructor called" << std::endl;
		this->_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			this->_array[i] = cpy._array[i];
	}
	~Array()
	{
		std::cout << "Destructor called" << std::endl;
		delete[] this->_array;
	}
	Array& operator=(const Array &rhs)
	{
		std::cout << "Assingment operator called" << std::endl;
		if (this->_array != NULL)
			delete[] this->_array;
		this->_size = rhs._size;
		this->_array = new T[_size];
		for (unsigned int i = 0; i < this->size(); i++)
			this->_array[i] = rhs._array[i];
		return (*this);
	}
	T& operator[](const unsigned int n)
	{
		if (n >= _size)
			throw OutOfRangeException();
		return this->_array[n];
	}
	unsigned int size() const
	{
		return _size;
	}
	struct OutOfRangeException : public std::exception
	{
		const char* what() const throw()
		{
			return ("Index is out of range");
		}
	};
private:
	T*				_array;
	unsigned int	_size;
};

#endif