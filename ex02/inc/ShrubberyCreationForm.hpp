/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:12:20 by albagarc          #+#    #+#             */
/*   Updated: 2023/11/19 19:25:27 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

class ShrubberyCreationForm : public AForm
{
	private:
	public:
		ShrubberyCreationForm(); //Constructor
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& original);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

};

#endif