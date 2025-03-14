/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:15:41 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 09:08:41 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

        Bureaucrat();
    public:
        Bureaucrat( const std::string& name, int grade );
        Bureaucrat( const Bureaucrat& src );
        Bureaucrat& operator=( const Bureaucrat& other );
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        
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