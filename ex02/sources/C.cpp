/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/03 15:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"


C::C() : Base()
{
	_type = "C";
	std::cout << "C default constructor called " << std::endl;
}

C::~C()
{
	std::cout << "C destructor called " << std::endl;
}
