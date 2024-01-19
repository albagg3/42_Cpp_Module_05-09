/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:53:26 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/19 11:03:32 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
int main ()
{
	int one_int = 1;
	int two_int = 2;
	float one_float = 1.1;
	float two_float = 2.2;
	int result_int;
	float result_float;

	result_int = max(one_int, two_int);
	std::cout << "Max between "<< one_int << " and " << two_int << " : "<< result_int << std::endl;
	result_int = min(one_int,two_int);
	std::cout << "Min between "<< one_int << " and " << two_int << " : "<< result_int << std::endl;
	swap(one_int,two_int);
	std::cout << "Function swap: "<< std::endl;
	std::cout << "one_int is:" << one_int << std::endl;
	std::cout << "two_float is:" << two_int << std::endl;
	std::cout << std::endl;
	result_float = max(one_float, two_float);
	std::cout << "Max between "<< one_float << " and " << two_float << " : "<< result_float << std::endl;
	result_float = min(one_float,two_float);
	std::cout << "Min between "<< one_float << " and " << two_float << " : "<< result_float << std::endl;
	swap(one_float,two_float);
	std::cout << "Function swap: "<< std::endl;
	std::cout << "one_float is:" << one_float << std::endl;
	std::cout << "two_float is:" << two_float << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}


// class Awesome
// 	{
// 		public:
// 			Awesome(void) : _n(0) {}
// 			Awesome( int n ) : _n( n ) {}
// 			Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
// 			bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 			bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// 			bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// 			bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// 			bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 			bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 			int get_n() const { return _n; }
// 		private:
// 			int _n;
// 	};

// 	std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// 	int main(void)
// 	{
// 		Awesome a(2), b(4);
// 		swap(a, b);
// 		std::cout << a << " " << b << std::endl;
// 		std::cout << max(a, b) << std::endl;
// 		std::cout << min(a, b) << std::endl;
// 		return (0);
// 	}