/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:38:39 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/29 16:53:02 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main () 
{
	//VECTOR
	try
	{
		int array[] = {1, 2 ,3, 4 , 5};
		std::vector<int> myVector(array, array + sizeof(array) / sizeof(array[0]));
		std::vector<int>::iterator it;
		std::vector<int> myvector;
		std::vector<int>::iterator result;

		result = easyFind(myVector, 7);
		std::cout << *result << std::endl;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//LIST
	try
	{
		int array[] = {1, 2 ,3, 4 , 5};
		std::list<int> myList(array, array + sizeof(array) / sizeof(array[0]));
		std::list<int>::iterator iter;
		iter = easyFind(myList, 3);
		std::cout << *iter << std::endl;
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
		
}