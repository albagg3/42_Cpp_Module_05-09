/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:38 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/12 13:12:48 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

class ScalarConverter 
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		~ScalarConverter();

		ScalarConverter&	operator=(const ScalarConverter& rhs);
	
	public:
		static void	convert(std::string input);
}

#endif