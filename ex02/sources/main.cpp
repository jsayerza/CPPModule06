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
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

void identify(Base* p)
{
    if (!p) {
        std::cout << "Error: NULL pointer" << std::endl;
        return;
    }

	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type: desconegut" << std::endl;
}

void identify(Base& p)
{
	try
	{
		((void)dynamic_cast<A&>(p));
		std::cout << "Type: A" << std::endl;
		return;
	}
	catch(const std::exception&) {}
	try
	{
		((void)dynamic_cast<B&>(p));
		std::cout << "Type: B" << std::endl;
		return;
	}
	catch(const std::exception&) {}
	try
	{
		((void)dynamic_cast<C&>(p));
		std::cout << "Type: C" << std::endl;
		return;
	}
	catch(const std::exception&) {}
	std::cout << "Type: desconegut" << std::endl;
}



Base* generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		std::cout << "Generat A" << std::endl;
		return (new A());
	case 1:
		std::cout << "Generat B" << std::endl;
		return (new B());
	default:
		std::cout << "Generat C" << std::endl;
		return (new C());
	}
}


int	main(void)
{
	srand(time(NULL));

	for (int i = 1; i < 6; i++)
	{
		std::cout << "\n=== Test " << i << std::endl;
		Base* base1 = generate();
		std::cout << "Usant pointer: ";
		identify(base1);
		std::cout << "Usant referencia: ";
		identify(*base1);
		delete base1;
	}

	std::cout << "\n=== Test pure Base object" << std::endl;
	Base* pureBase = new Base();
	identify(pureBase);
	identify(*pureBase);
	delete pureBase;

	std::cout << "\n=== Test NULL pointer" << std::endl;
	Base* nullPtr = NULL;
	identify(nullPtr);
	identify(*nullPtr);

	std::cout << "\n=== Test dynamic_cast" << std::endl;
	Base* a = new A();
	B* wrongCast = dynamic_cast<B*>(a);
	if (!wrongCast)
		std::cout << "OK: A no es pot fer cast a B (retorna NULL)" << std::endl;
	delete a;

	std::cout << "\n=== Test exception" << std::endl;
	Base* obj = new A();

	try {
		B& b = dynamic_cast<B&>(*obj);
		std::cout << "KO si imprimeix això" << std::endl;
		(void)b;
	} catch (std::exception& e) {
		std::cout << "OK! Exception llençada: " << e.what() << std::endl;
	}
	delete obj;

	return (0);
}

////Notes:
//// - dynamic_cast detecta el type automàticament usant RTTI (Run-Time Type Information)
//// - en punters: 	// Si és realment A*, retorna punter valid
                	// Si no, devuelve NULL
//// - en ref.: 	// Si és A, retorna referència
                	// Si no, llença std::bad_cast exception
//// - ((void)dynamic_cast<A&>(p));
		// dynamic_cast retorna un valor però com que no el necessito li faig (void) x evitar warning