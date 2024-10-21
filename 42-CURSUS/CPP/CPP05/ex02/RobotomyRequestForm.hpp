/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:40:57 by alonso            #+#    #+#             */
/*   Updated: 2024/10/18 11:58:13 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        const std::string   _target;

        RobotomyRequestForm();

    public:
        RobotomyRequestForm( const std::string& target );
        RobotomyRequestForm( const RobotomyRequestForm& src );
        ~RobotomyRequestForm();

        RobotomyRequestForm &operator=( RobotomyRequestForm& rhs );

        void        execute( const Bureaucrat& executor ) const;
};

#endif