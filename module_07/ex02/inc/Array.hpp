/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:48:52 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/18 18:12:01 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define GREY "\e[90m"
#define RESET "\e[0m"

template< typename T >
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
		
	public:
		Array<T>() : _array(NULL), _size(0)
		{
			std::cout << GREY << "Array default constructor called" << RESET << std::endl;
			return ;
		}
		Array<T>(unsigned int n) : _array(new T[n]()), _size(n)
		{
			std::cout << GREY << "Array constructor with " << n <<" elements called" << RESET << std::endl;
			return ;
		}
		Array<T>(Array<T> const & original)
		{
			this->_size = original._size;
			this->_array = new T[this->_size]();
			if(this->_size != 0)
			{
				for (unsigned int i = 0; i < this->_size; i++)
				{
					this->_array[i] = original._array[i];
				}
			}
			std::cout << GREY << "Array copy constructor called" << RESET << std::endl;
			return ;
		}
		~Array<T>()
		{
			if(this->_size != 0)
				delete [] this->_array;
			std::cout << GREY << "Array destructor called" << RESET << std::endl;
			return ;
		}

		Array<T>& operator=(Array<T> const &  rhs)
		{
			if(this == &rhs)
				return this;
			if(this->_size != 0)
				{
					delete [] this->_array;
					for(unsigned int i = 0; i < this->_size; i++)
					{
						this->_array[i] = rhs._array[i];
					}
				}
			std::cout << "Array assignation operator called" << std::endl;
			return *this;
		}
		
		unsigned int	getSize() const
		{
			return this->_size;
		}
};

#endif