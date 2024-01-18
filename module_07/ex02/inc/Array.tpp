// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Array.tpp                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/18 14:48:56 by albagarc          #+#    #+#             */
// /*   Updated: 2024/01/18 16:01:40 by albagarc         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */


// #include "Array.hpp"

// //Default constructor
// template< typename T >
// Array< T >::Array() : _array(NULL), _size(0)
// {
// 	std::cout << GREY << "Array default constructor called" << RESET << std::endl;
// 	return ;
// }

// //Constructor with a number of elements for the array
// template< typename T >
// Array< T >::Array(unsigned int n) : _array(new T[n]()), _size(n)
// {
// 	std::cout << GREY << "Array constructor with " << n <<" elements called" << RESET << std::endl;
// 	return ;
// }

// //Copy constructor
// template< typename T >
// Array< T >::Array(const & Array<T> original)  
// {
// 	this->_size = original._size;
// 	this->_array = new T[this->_size]();
// 	if(this->_size != 0)
// 	{
// 		for (unsigned int i = 0; i < this->_size; i++)
// 		{
// 			this->_array[i] = original._array[i];
// 		}
// 	}
// 	std::cout << GREY << "Array copy constructor called" << RESET << std::endl;
// 	return ;
// }

// //Destructor
// template< typename T >
// Array< T >::~Array() 
// {
// 	if(this->_size != 0)
// 		delete this->_array[];
// 	std::cout << GREY << "Array destructor called" << RESET << std::endl;
// 	return ;
// }


// template< typename T >
// T&	Array< T >::operator=(const Array<T>& rhs)
// {
// 	if(this == &rhs)
// 		return this;
// 	if(this->_size != 0)
// 		{
// 			delete this->_array[];
// 			for(unsiged int i = 0; i < this->_size; i++)
// 			{
// 				this->_array[i] = rhs._array[i]
// 			}
// 		}
// 	std::cout << "Array assignation operator called" << std::endl;
// 	return *this;
// }


// unsigned int	Array<T>::getSize() const
// {
// 	return this->_size;
// }