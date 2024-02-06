/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:19:51 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/06 18:13:49 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK__H__
#define __MUTANTSTACK__H__

#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <algorithm>
#include<iterator>

template <class T, class container = std::deque<T> >
class  MutantStack : public std::stack<T> 
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &original): std::stack<T, container>(original)
        {
            *this = original;
        }
        MutantStack&    operator=( const MutantStack& rhs )
        {
            std::stack< T, container >::operator=( rhs );
            return *this;
        }
        typedef typename container::iterator iterator;// tipo de dato typename container::iterator, para hacelro mas corto hacemos un typdef y lo llamamos iterator
        iterator begin() {
            return this->c.begin(); //estamos accediendo al contenedor que tiene el stack
        }

        iterator end() {
            return this->c.end();
        }
};

#endif