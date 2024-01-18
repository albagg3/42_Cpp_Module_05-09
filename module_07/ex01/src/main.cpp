/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:10:00 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/18 14:31:21 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <cstdlib>
#include <iostream>

template< typename T >
void functionToApply(T& element)
{
	std::cout << element << std::endl;
}



int main ()
{
	int arr_int[] = {1, 3, 5, 7};
	float arr_float[] = {1.2, 3.4, 5.6, 7.8};
	
	iter(arr_int, 4, &functionToApply<int>);
	iter(arr_float, 4, &functionToApply<float>);

    return 0;
}