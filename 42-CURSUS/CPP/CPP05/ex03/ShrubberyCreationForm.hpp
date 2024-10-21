/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:41:01 by alonso            #+#    #+#             */
/*   Updated: 2024/10/18 11:58:06 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
    private:
        const std::string   _target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm( const std::string& target );
        ShrubberyCreationForm( const ShrubberyCreationForm& src );
        ~ShrubberyCreationForm();

        ShrubberyCreationForm&  operator=( ShrubberyCreationForm& rhs );

        void        execute( const Bureaucrat& executor ) const;
};

#endif