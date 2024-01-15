/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/15 12:55:26 by albagarc         ###   ########.fr       */
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
		// std::cout <<casted_input<<std::endl;
		ScalarConverter::convert(argv[1]);
	}
}