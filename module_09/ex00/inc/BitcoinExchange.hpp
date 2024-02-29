/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:27 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/28 21:33:05 by albagarc         ###   ########.fr       */
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
		// std::list<std::string>				_inputFile;
		std::map<std::string, float>		_dataBase;

		bool	_validDataBase(std::ifstream& dataBase);
		void	_exchangeInput(std::ifstream& inputFile);
		
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream& inputFile, std::ifstream& dataBase);
		BitcoinExchange(const BitcoinExchange& original);
		~BitcoinExchange();
		
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		//EXCEPTIONS
		class	InvalidInputFormat : public std::exception
		{
			public:
				virtual const char* what() const throw();

		};

		class	InvalidDataBase : public std::exception
		{
			public:
				virtual const char* what() const throw();

		};
		

};

#endif