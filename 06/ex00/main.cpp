/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:33:16 by lmajerus          #+#    #+#             */
/*   Updated: 2024/10/02 15:42:20 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConv.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "One argument please" << std::endl;
        return (0);
    }
    ScalarConv::convert(argv[1]);
    return (0);
}