/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:38:35 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/29 16:52:54 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iterator>
#include <algorithm>
#include <stdexcept>

template< typename T >
typename T::iterator easyFind( T& container, int to_find)
{
	typename T::iterator	it;

	for(it = container.begin(); it != container.end(); ++it)
	{
		if(*it == to_find)
			return it;
	}
		throw std::out_of_range("Element not found"); 
}

#endif

// template< typename T >
// typename T::iterator easyFind( T& container, int to_find)
// {
// 	typename T::iterator	it;
// 	it = std::find(container.begin(), container.end(), to_find);
// 	if(it != container.end())
// 		return it;
// 	else
// 		throw std::out_of_range("Element not found"); 
// }