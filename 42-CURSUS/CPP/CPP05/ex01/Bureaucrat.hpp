/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:15:41 by alonso            #+#    #+#             */
/*   Updated: 2024/10/18 11:24:17 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

        Bureaucrat();
    public:
        Bureaucrat( const std::string& name, int grade );//cons con param
        Bureaucrat( const Bureaucrat& src );//copia
        Bureaucrat& operator=( const Bureaucrat& other );
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        
        void signForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high"; }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low"; }
        };
    };

    
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif