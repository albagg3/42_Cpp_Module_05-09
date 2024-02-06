/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:20:03 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/06 15:20:04 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define GREY "\e[90m"
#define RESET "\e[0m"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << YELLOW << "we have pushed a 5 and then a 17 and are trying to access to the top" << RESET << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << YELLOW << "we have deleted the last (17) and print the size" << RESET << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	std::cout << YELLOW << "we have pushed a 3, 5, 737 and then a 0 " << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << YELLOW << "we create two iterators one to the begining and the other one to the end" << RESET << std::endl;
	std::cout << YELLOW << "We will print in a loop the whole stack from begining to end" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);



	return 0;
}

// #include "MutantStack.hpp"

// int	main( void )
// {
// 	MutantStack<int>	mStack;
// 	MutantStack<int>	mStack1;

// 	std::cout << std::endl << "1. Should print < 2 >" << std::endl;
// 		mStack.push(1);
// 		mStack.push(2);
// 		std::cout << "< " << mStack.top() << " >" << std::endl;

// 	std::cout << std::endl <<"---------------------------------------------------" << std::endl;
		
// 	std::cout << "2. Should print < 1 >" << std::endl;
		
// 		mStack.pop();

// 		std::cout << "< " << mStack.size() << " >" << std::endl;

// 	std::cout << std::endl <<"---------------------------------------------------" << std::endl;

// 	std::cout << "3. Should print < 1 3 4 5 6 >" << std::endl;
// 		mStack.push(3);
// 		mStack.push(4);
// 		mStack.push(5);
// 		mStack.push(6);

// 		MutantStack<int>::iterator it = mStack.begin();
// 		MutantStack<int>::iterator ite = mStack.end();

// 		++it;
// 		--it;
// 		std::cout << "< ";
// 		while(it != ite)
// 		{
// 			std::cout << *it << " ";
// 			it++;
// 		}
// 		std::cout << ">" << std::endl;
// 	std::cout << std::endl <<"---------------------------------------------------" << std::endl;

// 	std::cout << "4. Should print < 4 2 >" << std::endl;
// 		mStack1.push(4);
// 		mStack1.push(2);

// 		mStack = mStack1;

// 		it = mStack.begin();
// 		ite = mStack.end();

// 		std::cout << "< ";
// 		while(it != ite)
// 		{
// 			std::cout << *it << " ";
// 			it++;
// 		}
// 		std::cout << ">" << std::endl;

// 	std::cout << std::endl << "---------------------------------------------------" << std::endl;
	
// 	std::stack<int> s(mStack);

// 	std::cout << "5. Should print < 4 2 >" << std::endl;

// 		MutantStack<int>	mStack2(mStack1);
// 		it = mStack2.begin();
// 		ite = mStack2.end();

// 		std::cout << "< ";
// 		while(it != ite)
// 		{
// 			std::cout << *it << " ";
// 			it++;
// 		}
// 		std::cout << ">" << std::endl;

// 	std::cout << std::endl << "---------------------------------------------------" << std::endl;
	
// 	return (0);
// }	