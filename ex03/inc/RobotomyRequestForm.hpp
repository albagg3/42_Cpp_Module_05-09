/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 15:14:27 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <stdlib.h>  

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
		RobotomyRequestForm();
		void	executingForm()const;

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& original);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		AForm*	clone();
};

std::ostream&	operator<<(std::ostream out, const RobotomyRequestForm& object);

#endif