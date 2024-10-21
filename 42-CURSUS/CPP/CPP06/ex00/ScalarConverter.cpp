/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:52:44 by alonso            #+#    #+#             */
/*   Updated: 2024/10/21 09:59:27 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
    // Convertir a int usando atoi
    try {
        int intValue = std::atoi(literal.c_str());
        std::cout << "int: " << intValue << std::endl;
    } catch (std::exception& e) {
        std::cout << "int: impossible" << std::endl;
    }

    // Convertir a float usando atof
    try {
        float floatValue = std::atof(literal.c_str());
        std::cout << "float: " << floatValue << "f" << std::endl;
    } catch (std::exception& e) {
        std::cout << "float: impossible" << std::endl;
    }

    // Aquí sigue el mismo proceso para los demás tipos (double, char)
}
