/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:51:55 by alonso            #+#    #+#             */
/*   Updated: 2024/10/21 09:52:30 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>


class ScalarConverter
{
public:
    static void convert(const std::string& literal);
private:
    ScalarConverter(); // No instanciable
    ~ScalarConverter();
};

#endif
