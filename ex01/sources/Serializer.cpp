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
{
	std::cout << "Serialize called" << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << "Deserialize called" << std::endl;
	return (reinterpret_cast<Data *>(raw));
}


std::ostream& operator<<(std::ostream& oStream, const Data& data)
{
	oStream << "Data punter: " << &data << std::endl;
	oStream << "Data str1: " << data.str1 << std::endl;
	oStream << "Data str2: " << data.str2 << std::endl;
	oStream << "Data int1: " << data.int1 << std::endl;
	oStream << std::endl;

	return (oStream);
}