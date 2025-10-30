/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 09:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/10/30 09:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./convert {param}" << std::endl;
		return (1);
	}

	std::string input(argv[1]);
	ScalarConverter::convert(input);
	// std::cerr << "argv[1]: " << argv[1] << std::endl;
	// ScalarConverter::convert(argv[1]);

	return (0);
}

/*
	test_converter("0");
	test_converter("42");
	test_converter("42.0");
	test_converter("42.0f");
	test_converter("42.2");
	test_converter("-42.2");
	test_converter("42.2f");
	test_converter("-inff");
	test_converter("+inf");
	test_converter("nan");
	test_converter("invalid");
	test_converter("42.2ff");
	test_converter("4.2.2f");
	test_converter("--42");
	test_converter("2147483647");
	test_converter("2147483648");
	test_converter("");
	test_converter("999999999999999999f");
	test_converter("999999999999999999999999999999999999999999.9");
	test_converter("-1");
*/
/*
https://github.com/mcombeau/Cpp_Modules/tree/main/cpp06
https://github.com/sylvainnicolet-42/42-CPP-Module-06/tree/master
*/