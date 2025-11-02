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
#include "../includes/ScalarConverter.hpp"

void	test_converter(std::string str) {
	std::cout << "--- Input: " << str << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./convert {param}" << std::endl;
		return (1);
	}

	std::string input(argv[1]);
	ScalarConverter::convert(input);

	// (void)argc;
	// (void)argv;
	// test_converter("0");
	// test_converter("42");
	// test_converter("42.0");
	// test_converter("42.2");
	// test_converter("-42.2");
	// test_converter("42.0f");
	// test_converter("42.2f");
	// test_converter("-42.2f");
	// test_converter("14.0f");
	// test_converter("14.2f");
	// test_converter("-14.2f");
	// test_converter("142.0f");
	// test_converter("142.2f");
	// test_converter("-142.2f");
	// test_converter("42...2f");
	// test_converter("42.2ff");
	// test_converter("4.2.2f");
	// test_converter("-inff");
	// test_converter("+inf");
	// test_converter("nan");
	// test_converter("invalid");
	// test_converter("--42");
	// test_converter("a");
	// test_converter("abc");
	// test_converter("");
	// test_converter("-1");
	// test_converter("2147483647");
		//La conversión 2147483647 → 2147483648.0f es el comportament estàndar de C++ degut a les limitacions de precisió de float. No és un bug, és una característica del tipus de dada.
		//Els floats només tenen ~7 dígits significatius i aquest arrodoniment és inevitable per a números tan grans.	
	// test_converter("2147483648");
	// test_converter("999999999999999999");
	// test_converter("-999999999999999999");
	// test_converter("999999999999999999f");
	// test_converter("999999999999999999999999999999999999999999.9");

	return (0);
}

// // Notes
// // Resum: Converteix string → double → float, validant que tota la conversió sigui correcta

// // cppdouble d = std::strtod(str.c_str(), &end); 
// // 	Converteix el string str a double. end apunta al primer caràcter no convertit.

// // cppbool validConversion = (end != str.c_str() && *end == '\0'); 
// // 	Verifica que: 
// // 		end != str.c_str() → Almenys un caràcter va ser convertit 
// // 		*end == '\0' → S'ha arribat al final de l'string (no han quedat caràcters sense processar)
// // 	Exemple:
// // 		"123" → vàlid (tot convertit)
// // 		"123abc" → invàlid (ha quedat "abc")
// // 		"abc" → invàlid (res convertit)

// // cppfloat f = static_cast<float>(d); 
// // 	Converteix el double a float de manera explícita, perdent precisió.
	