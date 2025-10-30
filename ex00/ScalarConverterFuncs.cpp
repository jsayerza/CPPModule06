/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterFuncs.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/30 10:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterFuncs.hpp"

int strLength(char* str)
{
	std::cout << "strLength str: " << str << std::endl;
	int i = 0;
	while (*str)
	{
		std::cout << "strLength str[" << i << "]: " << str[i] << std::endl;
		str++;
		i++;
	}
	return (i);
}

// bool isChar(char* str)
// {
// 	// std::string s(str);
// 	if ((strLength(str) == 3 && str[0] == '\'' && str[2] == '\''))
// 	{
// 		std::cout << "isChar str: " << str << " yesssss " << std::endl;
// 		return (true);
// 	}
// 	std::cout << "isChar str: " << str << " nopes " << std::endl;
// 	return (strLength(str) == 1 && !isdigit(str[0]));
// }

bool isChar (const std::string& str)
{
	std::cout << "str.length(): " << str.length() << std::endl;
	if ((str.length() == 3 && str[0] == '\'' && str[2] == '\''))
	{
		std::cout << "isChar str: " << str << " yesssss " << std::endl;
		return (true);
	}
	std::cout << "isChar str: " << str << " nopes " << std::endl;
	return (str.length() == 1 && !isdigit(str[0]));
}