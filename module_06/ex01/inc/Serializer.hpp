/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:36:55 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/16 18:51:49 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_H
# define SERIALIZER_H

#include "Data.hpp"
#include <iostream>

class Serializer{
	private:
		
		Serializer();
		Serializer(const Serializer& original);
		~Serializer();

		Serializer&	operator=(const Serializer& rhs);
	
	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif