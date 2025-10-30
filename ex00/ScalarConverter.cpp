/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterFuncs.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/30 10:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarConverterFuncs.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Constructor called " << std::endl;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called " << std::endl;
}

// void ScalarConverter::convert(char* str)
void ScalarConverter::convert(const std::string& str)
{
	std::cout << "str: " << str << std::endl;
	if (isChar(str))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}


