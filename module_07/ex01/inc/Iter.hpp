/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:43:10 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/18 14:30:51 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <cstdlib>

template< typename T >
void	iter(T* address, const size_t arr_length, void(*functionToApply)(T& element))
{
	for (size_t i = 0; i < arr_length; i++)
	{
		functionToApply(address[i]);
	}
}

#endif