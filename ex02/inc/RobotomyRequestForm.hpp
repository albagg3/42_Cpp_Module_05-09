/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 17:08:06 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <stdlib.h>  

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm();
		void	executingForm()const;

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& original);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
};

std::ostream&	operator<<(std::ostream out, const RobotomyRequestForm& object);

#endif