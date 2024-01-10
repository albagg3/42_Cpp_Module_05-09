/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 18:20:46 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

class ScalarConverter 
{
	private:
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& rhs);

		void	convert(std::string input);
}

#endif