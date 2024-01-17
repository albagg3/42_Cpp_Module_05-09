/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:53:26 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/17 18:37:59 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
int main ()
{
	int one_int = 1;
	int two_int = 2;
	float one_float = 1.1;
	float two_float = 2.2;
	int result_int;
	float result_float;

	result_int = max(one_int, two_int);
	std::cout << "Max between "<< one_int << " and " << two_int << " : "<< result_int << std::endl;
	result_int = min(one_int,two_int);
	std::cout << "Min between "<< one_int << " and " << two_int << " : "<< result_int << std::endl;
	swap(one_int,two_int);
	std::cout << "Function swap: "<< std::endl;
	std::cout << "one_int is:" << one_int << std::endl;
	std::cout << "two_float is:" << two_int << std::endl;
	std::cout << std::endl;
	result_float = max(one_float, two_float);
	std::cout << "Max between "<< one_float << " and " << two_float << " : "<< result_float << std::endl;
	result_float = min(one_float,two_float);
	std::cout << "Min between "<< one_float << " and " << two_float << " : "<< result_float << std::endl;
	swap(one_float,two_float);
	std::cout << "Function swap: "<< std::endl;
	std::cout << "one_float is:" << one_float << std::endl;
	std::cout << "two_float is:" << two_float << std::endl;
}