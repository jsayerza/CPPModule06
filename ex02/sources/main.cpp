/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsayerza <jsayerza@student.42barcelona.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:00:00 by jsayerza          #+#    #+#             */
/*   Updated: 2025/11/03 15:00:00 by jsayerza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "../includes/Base.hpp"

int	main(void)
{
    std::cout << "=== Crear ===" << std::endl;
	srand(time(NULL));

	Base* base1 = Base::generate();

	delete base1;

	return (0);
}

