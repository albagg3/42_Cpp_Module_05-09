/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:27 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/23 12:27:58 by albagarc         ###   ########.fr       */
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

class BitcoinExchange
{
	private:
		std::list<std::string>				_inputFile;
		std::map<std::string, float>		_dataBase;

		bool	_validDataBase(std::ifstream& dataBase);
		bool	_validDate(std::string date);
		bool	_validNum(std::string num);
		int		_howManyDelimiters(std::string str, std::string delimiter);
		
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream& inputFile, std::ifstream& dataBase);
		BitcoinExchange(const BitcoinExchange& original);
		~BitcoinExchange();
		
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		//EXCEPTIONS
		// class	InvalidInputFile : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw();

		// };

		class	InvalidDataBase : public std::exception
		{
			public:
				virtual const char* what() const throw();

		};
		

};

#endif