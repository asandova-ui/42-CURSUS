/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:22 by alonso            #+#    #+#             */
/*   Updated: 2024/10/18 11:30:44 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExec;

        Form();
    public:
        Form(const std::string &name, int gradeToSign, int gradeToExec);
        Form(const std::string& name, int gradeToSign);
        ~Form();

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned( const Bureaucrat& bure );

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "FormExcep : Grade too high"; }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "FormExcep : Grade too low"; }
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif