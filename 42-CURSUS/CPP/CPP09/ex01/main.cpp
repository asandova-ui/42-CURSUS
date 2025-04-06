/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:30:38 by alonso            #+#    #+#             */
/*   Updated: 2025/04/06 18:31:35 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpn;
    rpn.run(av[1]);

    return EXIT_SUCCESS;
}