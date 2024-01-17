/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/17 15:33:19 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"


Base* generate(void)
{
	std::srand(std::time(nullptr));
	int random_value = 1 + std::rand() % 3;
	switch(random_value)
	{
		case 1:
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();
	}
	return nullptr;
}

//A pointer can be null thats why we can check if the type corresponds with an if
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "It's not A, B or C" << std::endl;
	}
}

//A reference can't be null thats why we can check if the type corresponds with a try catch
void identify(Base& p)
{ 
	try{
		Base try_A = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}catch(std::exception &e)
	{
		;
	}
	try{
		Base try_B = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}catch(std::exception &e)
	{
		;
	}
	try{
		Base try_C = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}catch(std::exception &e)
	{
		;
	}
	std::cout << "It's not A, B or C" << std::endl;

}

int	main()
{
	Base* base_random;
	
	base_random = generate();
	std::cout << "Identify passing a pointer" << std::endl;
	identify(base_random);
	std::cout << "Identify passing a reference" << std::endl;
	identify(*base_random);
}