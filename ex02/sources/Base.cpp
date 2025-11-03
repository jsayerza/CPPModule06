/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/03 14:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::Base() : _type()
{
	std::cout << "Base default constructor called " << std::endl;
}

Base::~Base()
{
	std::cout << "Base destructor called " << std::endl;
}


Base* Base::generate(void)
{
	Base* newBase;
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		newBase = new A();
		break;
	case 1:
		newBase = new B();
		break;
	
	default:
		newBase = new C();
		break;
	}

	return (newBase);
}

void Base::identify(Base* p)
{
	(void)p;
}
void Base::identify(Base& p)
{
	(void)p;
}
