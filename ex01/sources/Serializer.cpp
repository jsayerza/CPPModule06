/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/02 12:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called " << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	if (this != &other)
		*this = other;
	std::cout << "Serializer copy constructor called " << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
	std::cout << "Serializer assignment operator constructor called " << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called " << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{}
Data* Serializer::deserialize(uintptr_t raw)
{}

std::ostream& operator<<(std::ostream& oStream, const Data& data)
{
	std::cout << "Data str1: " data->str1 << std::endl;
	std::cout << "Data str2: " data->str2 << std::endl;
	std::cout << "Data int1: " data->int1 << std::endl;
	std::cout << std::endl;
}