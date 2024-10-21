/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:44 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 19:09:40 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//******* CLASS PmergeMe ************//

PmergeMe::PmergeMe()
{
	std::cout << GREY << "Default PmergeMe constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &original)
{
	*this = original;
}

PmergeMe::~PmergeMe()
{
	std::cout << GREY << "Default PmergeMe destructor called" << RESET << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

void PmergeMe::mergeVec(std::vector<int> &vec, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> leftArr(n1), rightArr(n2);

	for (int i = 0; i < n1; i++)
		leftArr[i] = vec[left + i];
	for (int i = 0; i < n2; i++)
		rightArr[i] = vec[mid + 1 + i];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			vec[k] = leftArr[i];
			i++;
		}
		else
		{
			vec[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		vec[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		vec[k] = rightArr[j];
		j++;
		k++;
	}
}

// Función de merge para std::deque
void PmergeMe::mergeDeq(std::deque<int> &deq, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> leftArr(n1), rightArr(n2);

	for (int i = 0; i < n1; i++)
		leftArr[i] = deq[left + i];
	for (int i = 0; i < n2; i++)
		rightArr[i] = deq[mid + 1 + i];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			deq[k] = leftArr[i];
			i++;
		}
		else
		{
			deq[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		deq[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		deq[k] = rightArr[j];
		j++;
		k++;
	}
}

// Algoritmo merge-insert sort para std::vector
void PmergeMe::mergeInsertSortVec(std::vector<int> &vec, int left, int right)
{
	if (left < right)
	{
		if (right - left <= 5)
		{ // Caso base: ordenamiento por inserción para pocos elementos
			for (int i = left + 1; i <= right; i++)
			{
				int key = vec[i];
				int j = i - 1;
				while (j >= left && vec[j] > key)
				{
					vec[j + 1] = vec[j];
					j--;
				}
				vec[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsertSortVec(vec, left, mid);
			mergeInsertSortVec(vec, mid + 1, right);
			mergeVec(vec, left, mid, right);
		}
	}
}

// Algoritmo merge-insert sort para std::deque
void PmergeMe::mergeInsertSortDeq(std::deque<int> &deq, int left, int right)
{
	if (left < right)
	{
		if (right - left <= 5)
		{ // Caso base: ordenamiento por inserción para pocos elementos
			for (int i = left + 1; i <= right; i++)
			{
				int key = deq[i];
				int j = i - 1;
				while (j >= left && deq[j] > key)
				{
					deq[j + 1] = deq[j];
					j--;
				}
				deq[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeInsertSortDeq(deq, left, mid);
			mergeInsertSortDeq(deq, mid + 1, right);
			mergeDeq(deq, left, mid, right);
		}
	}
}

// Función para std::vector
void PmergeMe::mergeInsertSortVector(std::vector<int> &vec)
{
	mergeInsertSortVec(vec, 0, vec.size() - 1);
}

// Función para std::deque
void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq)
{
	mergeInsertSortDeq(deq, 0, deq.size() - 1);
}

// Imprimir contenido de std::vector
void PmergeMe::printContainerVec(const std::vector<int> &vec) const
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

// Imprimir contenido de std::deque
void PmergeMe::printContainerDeq(const std::deque<int> &deq) const
{
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << deq[i] << " ";
	std::cout << std::endl;
}
