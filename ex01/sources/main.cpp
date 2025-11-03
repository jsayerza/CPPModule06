/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/02 13:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../includes/Serializer.hpp"

int	main(void)
{
    std::cout << "=== Crear estructura i punter original ===" << std::endl;
	Data data;
	data.str1 = "data str1";
	data.str2 = "data str2";
	data.int1 = 42;
	std::cout << data;

    std::cout << "=== Serialitzar ===" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value:    " << raw << std::endl << std::endl;

    std::cout << "=== Deserialitzar i crear nou punter a estructura ===" << std::endl;
	Data* data2 = Serializer::deserialize(raw);
	std::cout << *data2;

    std::cout << "=== Verificació ===" << std::endl;
    if (&data == data2)
    	std::cout << "OK! Els punters son iguals!" << std::endl;
    else
	{
		std::cout << "KO! Els punters son diferents!" << std::endl;
	}

    std::cout << "\n=== Test d'identitat===" << std::endl;
    data2->int1 = 100;
    std::cout << "Després de modificar mitjançant un punter deserialitzat:" << std::endl;
    std::cout << "Original data.int1:  " << data.int1 << std::endl;
    
    if (data.int1 == 100)
	{	
        std::cout << "OK! Apunten al mateix objecte!" << std::endl;
	}
	else
	{	
        std::cout << "KO! NO apunten al mateix objecte!" << std::endl;
	}
	std::cout << std::endl;

	return (0);
}

////Notes: 
////- reinterpret_cast converteix el punter a integer i viceversa sense perdre informació.
////- Són static porquè no necessiten estat de instància. 
////   Les funcions només fan conversions de tipus (reinterpret_cast). 
////   No necessiten accedir a cap atribut de la classe, es poden usar directament.