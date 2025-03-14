/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:15:47 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 09:18:48 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    try {
        Bureaucrat bureaucrat("ash", 149);

        //std::cout << bureaucrat << std::endl;

        //bureaucrat.incrementGrade();

        bureaucrat.decrementGrade();
  
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
        
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
