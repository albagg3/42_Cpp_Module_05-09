/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:27 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 12:18:16 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <exception>
#include <cstdlib>
#include <limits>

#define GREY "\e[90m"
#define RESET "\e[0m"
#define RED "\e[91m"
#define GREEN "\e[92m"

class BitcoinExchange
{
	private:
		std::map<std::string, float>		_dataBase;

		bool	_validDataBase(std::ifstream& dataBase);
		void	_exchangeInput(std::ifstream& inputFile);
		BitcoinExchange();
		
	public:
		//CANONICAL + CONSTRUCTOR 
		BitcoinExchange(std::ifstream& inputFile, std::ifstream& dataBase);
		BitcoinExchange(const BitcoinExchange& original);
		~BitcoinExchange();
		
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		//EXCEPTIONS
		class	InvalidDataBase : public std::exception
		{
			public:
				virtual const char* what() const throw();

		};
};

#endif