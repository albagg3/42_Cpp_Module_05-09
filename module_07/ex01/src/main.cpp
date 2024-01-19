/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:10:00 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/19 11:06:15 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <cstdlib>
#include <iostream>

template< typename T >
void print(T& element)
{
	std::cout << element << std::endl;
}



int main ()
{
	int arr_int[] = {1, 3, 5, 7};
	float arr_float[] = {1.2, 3.4, 5.6, 7.8};
	
	//size returns the size in bytes
	// std::cout << sizeof(arr_int) << std::endl;
	// std::cout << sizeof(arr_int[0]) << std::endl;

	iter(arr_int, sizeof(arr_int)/sizeof(arr_int[0]), &print<int>);
	iter(arr_float, 4, &print<float>);

    return 0;
}

// class Awesome
// 	{
// 		public:
// 			Awesome( void ) : _n( 42 ) { return; }
// 			int get( void ) const { return this->_n; }
// 		private:
// 			int _n;
// 	};

// 	std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
	
// 	template< typename T >
// 	void print( T const & x ) { std::cout << x << std::endl; return; }

// 	int main()
// 	{
// 		int tab[] = { 0, 1, 2, 3, 4 }; 
// 		Awesome tab2[5];
// 		iter( tab, 5, print );
// 		iter( tab2, 5, print );
// 		return 0;
// 	}
