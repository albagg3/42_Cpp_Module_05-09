/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/16 16:38:46 by albagarc         ###   ########.fr       */
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
		try{
			ScalarConverter::convert(argv[1]);
		}
		  catch(std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

// std::cout << "char:" << static_cast<char>(input)<<std::endl;
// std::cout << "int" << static_cast<int>(input)<<std::endl;
// std::cout << "float" << static_cast<float>(input)<<std::endl;
// std::cout << "double" << static_cast<double>(input)<<std::endl;