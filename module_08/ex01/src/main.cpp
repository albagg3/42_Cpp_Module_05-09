#include "Span.hpp"
#include <iostream>

int main (void)
{
	Span	test1 = Span(5);
	unsigned int longestSpan; 
	unsigned int shortestSpan; 
	try{

		
		test1.addNumber(6);
		test1.addNumber(3);
		test1.addNumber(17);
		test1.addNumber(9);
		test1.addNumber(11);
		// test1.printList();
		longestSpan = test1.longestSpan();
		shortestSpan = test1.shortestSpan();
		std::cout << longestSpan << std::endl;
		std::cout << shortestSpan << std::endl;
		
	}catch(const std::exception &e){
			std::cout << e.what() << std::endl;
	}	

}