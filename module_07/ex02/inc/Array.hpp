/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:48:52 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/19 12:20:49 by albagarc         ###   ########.fr       */
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
		//CONSTRUCTOR DEFAULT
		Array<T>() : _array(NULL), _size(0)
		{
			std::cout << GREY << "Array default constructor called" << RESET << std::endl;
			return ;
		}

		//CONSTUCTOR WITH A NUMBER OF ELEMENTS
		Array<T>(unsigned int n) : _array(new T[n]()), _size(n)
		{
			std::cout << GREY << "Array constructor with " << n <<" elements called" << RESET << std::endl;
			return ;
		}

		//COPY CONSTRUCTOR
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

		//DESTRUCTOR
		~Array<T>()
		{
			if(this->_size != 0)
				delete [] this->_array;
			std::cout << GREY << "Array destructor called" << RESET << std::endl;
			return ;
		}

		//OPERATORS
		Array<T>& operator=(Array<T> const &  rhs)
		{
			if(this == &rhs)
				return *this;
			else
			{
				delete [] this->_array;
				this->_size = rhs.size();
				this->_array = new T[this->_size];
				for(unsigned int i = 0; i < this->_size ; i++)
				{
					this->_array[i] = rhs._array[i];
				}

			}	
				
			std::cout << GREY << "Array assignation operator called" << RESET << std::endl;
			return *this;
		}

		T& operator[](unsigned int index) 
		{
			if(index > this->_size - 1 || index < 0)
				throw OutOfBoundsException();
      		return this->_array[index];
    	}
		
		unsigned int	size() const
		{
			return this->_size;
		}

		//EXCEPTIONS
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					
					return (RED"Out of bounds of the array");

				}
		};
};

#endif