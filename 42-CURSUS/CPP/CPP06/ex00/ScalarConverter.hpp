/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:51:55 by alonso            #+#    #+#             */
/*   Updated: 2025/03/14 10:05:31 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <climits>
#include <sstream>
#include <limits>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <cfloat>

enum e_type {
    DEFAULT,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NNAN,
    INF,
    NINF
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &cpy);
        ScalarConverter& operator = (ScalarConverter const &cpy);
        static int _type;
        static double _value;
    public:
        ~ScalarConverter();
        static void convert(std::string const&);
        class   NonDisplayableException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class   ImpossibleException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif // CONVERTER_HPP
