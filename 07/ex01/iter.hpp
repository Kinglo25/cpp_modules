/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:46 by lmajerus          #+#    #+#             */
/*   Updated: 2024/10/08 15:47:29 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <stdio.h>

template <typename T>
void	iter(T* tab, size_t size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		f(tab[i]);
}

#endif