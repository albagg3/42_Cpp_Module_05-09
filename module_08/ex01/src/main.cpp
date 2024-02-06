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
	int longestSpan; 
	int shortestSpan; 
	
	std::cout << YELLOW << "Subjects's main add 5 numbers to your Span" << RESET <<std::endl;

	try{

		
		test1.addNumber(3);
		test1.addNumber(6);
		test1.addNumber(17);
		test1.addNumber(9);
		test1.addNumber(11);
		test1.printList();
		longestSpan = test1.longestSpan();
		shortestSpan = test1.shortestSpan();
		std::cout << "Longest span: "<< longestSpan << std::endl;
		std::cout << "Shortest span: " << shortestSpan << std::endl;
		
	}catch(const std::exception &e){
			std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "Add 6 numbers to your Span" << RESET <<std::endl;

	try{

		
		test1.addNumber(11);
		test1.printList();
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

// #include <iostream>
// #include <limits.h>
// #include "Span.hpp"

// int	main(void)
// {
// 	std::cout << "1. Create a Span" << std::endl;

// 		Span	sp = Span(5);
// 		Span	sp1 = Span(10);

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "2. Try to calculate longest span with 0 elements ANSWER = Exception" << std::endl;

// 		try
// 		{
// 			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << std::endl << "3. Try to calculate shortest span with 0 elements ANSWER = Exception" << std::endl;

// 		try
// 		{
// 			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "std::exception: "<<e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;
	
// 	std::cout << std::endl << "4. Add number -5 and try to calculate shortest span with 0 elements ANSWER = Exception" << std::endl;

// 		try
// 		{
// 			sp.addNumber(-5);
// 			sp.printList();
// 			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "std::exception: "<<e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;
	
// 	std::cout << std::endl << "5. Add numbers 2 3" << std::endl;
// 		try
// 		{
// 			sp.addNumber(2);
// 			sp.addNumber(3);
// 			sp.printList();
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "std::exception: "<<e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "6. Calculate longest span ANSWER = 8" << std::endl;

// 		try
// 		{
// 			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "7. Calculate shortest span ANSWER = 1" << std::endl;

// 		try
// 		{
// 			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "std::exception: "<<e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "8. Add INT_MAX & INT_MIN and calculate longest span ANSWER = 4294967295" << std::endl;

// 		try
// 		{
// 			sp.addNumber(INT_MAX);
// 			sp.addNumber(INT_MIN);
// 			sp.printList();
// 			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "std::exception: "<<e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "9. Try to add more numbers ANSWER = Exception" << std::endl;

// 		try
// 		{
// 			sp.addNumber(INT_MAX);
// 			sp.addNumber(INT_MIN);
// 			sp.printList();
// 			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << "std::exception: "<<e.what() << '\n';
// 		}

// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "10. Create new Span wit number < 5 5 > and calculate longest and shortest span ANSWER 0 (for both)" << std::endl;

// 		try
// 		{
// 			sp1.addNumber(5);
// 			sp1.addNumber(5);
// 			sp1.printList();
// 			std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
// 			std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;

// 	std::cout << std::endl << "11. Add new list to Span" << std::endl;

// 		try	
// 		{
// 			std::list<int> list;
// 			list.push_back(1);
// 			list.push_back(2);
// 			list.push_back(3);
// 			std::list<int>::iterator it1 = list.begin();
// 			std::list<int>::iterator it2 = list.end();

// 			sp1.addNumbers(it1, it2);
// 			sp1.printList();
// 			std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
// 			std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;
	
	
// 	std::cout << std::endl << "12. test 10k numbers from 0 - 9 999" << std::endl;
// 		try	
// 		{
// 			Span tenthousands = Span(10000);
// 			for (int i = 0; i < 10000; i++)
// 				tenthousands.addNumber(i);
// 			std::cout <<  "LongestSpan: " << tenthousands.longestSpan() << std::endl;
// 			std::cout <<  "ShorterSpan: " << tenthousands.shortestSpan() << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	std::cout << std::endl << "----------------------------------------------------" << std::endl;
// 	return (0);
// }