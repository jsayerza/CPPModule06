/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/03 15:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/B.hpp"


B::B() : Base()
{
	_type = "B";
	std::cout << "B default constructor called " << std::endl;
}

B::~B()
{
	std::cout << "B destructor called " << std::endl;
}
