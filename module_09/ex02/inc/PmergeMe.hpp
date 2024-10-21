/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:34 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 19:08:53 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <stack>

#define GREY "\e[90m"
#define RESET "\e[0m"
#define RED "\e[91m"
#define GREEN "\e[92m"

class PmergeMe
{
private:
	void mergeInsertSortVec(std::vector<int> &vec, int left, int right);
	void mergeInsertSortDeq(std::deque<int> &deq, int left, int right);

	void mergeVec(std::vector<int> &vec, int left, int mid, int right);
	void mergeDeq(std::deque<int> &deq, int left, int mid, int right);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &original);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);

	void mergeInsertSortVector(std::vector<int> &vec);
	void mergeInsertSortDeque(std::deque<int> &deq);

	void printContainerVec(const std::vector<int> &vec) const;
	void printContainerDeq(const std::deque<int> &deq) const;
};

#endif