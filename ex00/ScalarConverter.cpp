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
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cfloat>
#include <cstdlib>
#include <climits>

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


void printChar (int c, bool isPossible = true)
{
	if (!isPossible || c < 0 || c > 127)
		std::cout << "char:   impossible" << std::endl;
	else if (c < 32 || c == 127)
		std::cout << "char:   Non displayable" << std::endl;
	else
		std::cout << "char:   " << static_cast<char>(c) << std::endl;
}

void printInt (int i, bool isPossible = true)
{
	if (!isPossible)
		std::cout << "int:    impossible" << std::endl;
	else
		std::cout << "int:    " << i << std::endl;
}

void	printFloat(float f, bool isPossible = true)
{
	// std::cout << "   printFloat - f: " << f << std::endl;
	if (!isPossible)
		std::cout << "float:  impossible" << std::endl;
	else if (std::isinf(f) || f > FLT_MAX || f < -FLT_MAX)
	{
		if (f > 0)
    		std::cout << "float:  +inff" << std::endl;
		else
    		std::cout << "float:  -inff" << std::endl;
	}
	else if (std::isnan(f))
    	std::cout << "float:  nanf" << std::endl;
	else
	{
		float absF = std::abs(f);
		if (absF > 1e7 || (absF > 0 && absF < 1e-6))
			std::cout << "float:  " << std::scientific 
                      << std::setprecision(1) << f << "f" << std::endl;	
		else
			std::cout << "float:  " << std::setprecision(1) << std::fixed << f << "f" << std::endl;
	}
}

void	printDouble(double d, bool isPossible = true)
{
	// std::cout << "   printDouble - d: " << d << std::endl;
	if (!isPossible)
		std::cout << "double: impossible" << std::endl;
	else if (std::isinf(d))
		{
		if (d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
		}
	else if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::abs(d) > 1e15)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}


////Convert to functions
void	toPseudoLiteral(const std::string& str)
{
	printChar('c', false);
	printInt(0, false);
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::cout << "float:  " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float:  " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

void	toChar(const std::string& str)
{
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

float	toFloat(std::string str)
{
	if (!str.empty() && str[str.length() -1] == 'f')
		str.erase(str.length() - 1);

	// strtod controla overflow/inf, posa inf, si aplica
	char* end;
    double d = std::strtod(str.c_str(), &end);
	bool validConversion = (end != str.c_str() && *end == '\0');

	float f = static_cast<float>(d);

	std::stringstream ss1;
	int i;
	ss1 << str;
	ss1 >> i;

	printChar(static_cast<int>(f));
	if (ss1.fail() || d < INT_MIN || d > INT_MAX)
		printInt(0, false);
	else
		printInt(static_cast<int>(d));	//// Uso double per a millor rang
	if (!validConversion)
		printFloat(0, false);
	else
		printFloat(f);
	printDouble(d);

	ss1.clear();

	return (f);
}

void	toDouble(const std::string& str)
{
	//// strtod controla overflow/inf, posa inf, si aplica
	char* end;
    double d = std::strtod(str.c_str(), &end);
	bool validDouble = (end != str.c_str() && (*end == '\0' || *end == 'f'));

	int i;
	std::stringstream ss1;
	ss1 << str;
	ss1 >> i;

	printChar(static_cast<int>(d));
	if (ss1.fail() || d < INT_MIN || d > INT_MAX)
		printInt(0, false);
	else
		printInt(static_cast<int>(d));
	if (d < -FLT_MAX || d > FLT_MAX)
		printFloat(0, false);
	else
		printFloat(static_cast<float>(d));
	if (!validDouble)
		printDouble(0, false);
	else
		printDouble(d);
	
	ss1.clear();
}

void	toInt(const std::string& str)
{
	// std::cout << "   toInt - str: " << str << std::endl;
	//// strtod controla overflow/inf, posa inf, si aplica
	char* end;
    double d = std::strtod(str.c_str(), &end);
	bool validConversion = (end != str.c_str() && *end == '\0');

	float f = static_cast<float>(d);

	std::stringstream ss1;
	int i;
	ss1 << str;
	ss1 >> i;

	printChar(static_cast<int>(i));
	if (ss1.fail())
		printInt(0, false);
	else
		printInt(static_cast<int>(i));
	printFloat(f);
	if (!validConversion)
		printDouble(0, false);
	else
		printDouble(d);
	
	ss1.clear();
}


////Check functions
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


////Convert main function
void ScalarConverter::convert(const std::string& str)
{
	if (!isValid(str))
	{
		printChar('c', false);
		printInt(0, false);
		printFloat(0, false);
		printDouble(0, false);
		return;
	}
	if (isPseudoLiteral(str))
	{
		toPseudoLiteral(str);
		return;
	}
	if (str.length() == 1 && !isdigit(str[0]))
		toChar(str);
	else if (!str.empty() && str[str.length() -1] == 'f')
		toFloat(str);
	else if (str.find('.') != std::string::npos)
		toDouble(str);
	else
		toInt(str);
}
