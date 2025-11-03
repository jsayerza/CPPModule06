/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/03 15:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"


A::A() : Base()
{
	_type = "A";
	std::cout << "A default constructor called " << std::endl;
}

A::~A()
{
	std::cout << "A destructor called " << std::endl;
}
