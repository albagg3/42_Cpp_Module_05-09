#include "Span.hpp"
#include <iostream>

#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define GREY "\e[90m"
#define RESET "\e[0m"


int main (void)
{
	Span	test1 = Span(5);
	Span	test2 = Span(5);
	unsigned int longestSpan; 
	unsigned int shortestSpan; 
	
	std::cout << YELLOW << "Subjects's main add 5 numbers to your Span" << RESET <<std::endl;

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

	std::cout << YELLOW << "Add 6 numbers to your Span" << RESET <<std::endl;

	try{

		
		test1.addNumber(11);
		// test1.printList();
		longestSpan = test1.longestSpan();
		shortestSpan = test1.shortestSpan();
		std::cout << longestSpan << std::endl;
		std::cout << shortestSpan << std::endl;
		
	}catch(const std::exception &e){
			std::cout << e.what() << std::endl;
	}
	std::cout << YELLOW << "Only one number in the span" << RESET <<std::endl;

	try{

		
		test2.addNumber(6);
		// test2.printList();
		longestSpan = test2.longestSpan();
		shortestSpan = test2.shortestSpan();
		std::cout << longestSpan << std::endl;
		std::cout << shortestSpan << std::endl;
		
	}catch(const std::exception &e){
			std::cout << e.what() << std::endl;
	}
		

}