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
#include <iomanip>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called " << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	if (this != &other)
		*this = other;
	std::cout << "ScalarConverter copy constructor called " << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
	std::cout << "ScalarConverter assignment operator constructor called " << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called " << std::endl;
}


//// Functions
void printInt (int i, bool isPossible = true)
{
	if (!isPossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: '" << i << "'" << std::endl;
}

void printChar (char c, bool isPossible = true)
{
	if (!isPossible)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	printFloat(float f, bool isPossible = true) {
	if (!isPossible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
}

void	printDouble(double d, bool isPossible = true) {
	if (!isPossible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

bool	isPseudoLiteral(const std::string& str)
{
	std::string pseudoLiterals[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};
	for (size_t i = 0; i < 6; i++)
	{
		if (str == pseudoLiterals[i])
			return (true);
	}
	return (false);
}

void	toPseudoLiteral(const std::string& str)
{
	printChar('c', false);
	printInt(0, false);
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

bool	isValid(const std::string& str) 
{
	int numDots = 0;
	int numFs = 0;
	int numSigns = 0;

	if (str.empty())
		return (false);
	if (str.length() == 1)
		return (true);
	if (isPseudoLiteral(str))
		return (true);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '+' && str[i] != '-' && str[i] != 'f')
			return (false);
		if (str[i] == '.')
			numDots++;
		if (str[i] == 'f')
			numFs++;
		if (str[i] == '+' || str[i] == '-')
			numSigns++;
		if (numDots > 1 || numFs > 1 || numSigns > 1)
			return (false);
	}
	return (true);
}

void ScalarConverter::convert(const std::string& str)
{
	// std::cout << "str: " << str << std::endl;
	if (!isValid(str))
	{
		printChar('c', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}
	if (isPseudoLiteral(str))
		toPseudoLiteral(str);
	else
		std::cout << "altres" << std::endl;
}


