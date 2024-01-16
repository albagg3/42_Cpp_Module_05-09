/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:38 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/16 16:34:11 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

// #include <cstdlib> //for codespaces use this and compile with g++
#include <iostream>
#include <string> 
#include <iomanip>
#include <limits>
#include <cctype>
#include <cmath>

class ScalarConverter 
{
	private:
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& rhs);
	
	public:
		static void	convert(std::string input);
};

#endif