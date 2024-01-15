/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/15 15:58:54 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <string>
int main (int argc, char **argv)
{
	(void)argv;
	if(argc != 2)
	{
		std::cout << "Please, only one input" << std::endl;
	}
	else
	{
		// int casted_input;
		// casted_input = stoi("c");
		// std::cout << "char:" << static_cast<char>(42.2)<<std::endl;
		// std::cout << "int" << static_cast<int>(42.2)<<std::endl;
		// std::cout << "float" << static_cast<float>(42.2)<<std::endl;
		// std::cout << "double" << static_cast<double>(42.2)<<std::endl;
		ScalarConverter::convert(argv[1]);
	}
}