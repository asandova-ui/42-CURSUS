/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:58:13 by alonso            #+#    #+#             */
/*   Updated: 2024/10/18 11:26:54 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, int gradeToSign) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(0)
{
    if (gradeToSign < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    
}

const std::string &Form::getName() const
{
    return _name;
}

int Form::getGradeToExecute() const
{
    return _gradeToExec;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

bool Form::isSigned() const
{
    return _signed;
}

void Form::beSigned( const Bureaucrat &bure )
{
    if (bure.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", form signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute() << ".";
    return os;
}