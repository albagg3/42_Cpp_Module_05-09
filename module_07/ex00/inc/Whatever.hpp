/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:23:38 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/17 18:21:15 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_H
#define WHATEVER_H

// #include <iostream>

template < typename T >
const T&	max(const T& x, const  T& y) 
{
	return (y >= x ? y : x);
}

template < typename T >
const T&	min(const T& x, const  T& y) 
{
	return (y <= x ? y : x);
}

template < typename T >
void	swap(T& x, T& y) 
{
	T	aux;

	aux = x;
	x = y;
	y = aux;
	return ;
}

#endif
// std::template library