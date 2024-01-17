/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/16 16:33:25 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

//Constructor default
Serializer::Serializer()
{
	std::cout << "Serializer default Constructor called" << std::endl;
}

//Copy Constructor
Serializer::Serializer(const Serializer& original) 
{
	(void) original;
	std::cout << "Serializer copy Constructor called" << std::endl;
}

//Destructor
Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

//Assignation operator
Serializer& Serializer::operator=(const Serializer& rhs)
{
	(void) rhs;
	std::cout << "Assignation operator of serializer called" << std::endl;
	return *this;
}


//Static function
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t unsigned_int_type;
	unsigned_int_type = reinterpret_cast<uintptr_t>(ptr);	
	return unsigned_int_type;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* data_pointer;
	data_pointer = reinterpret_cast<Data*>(raw);	
	return data_pointer;
}


