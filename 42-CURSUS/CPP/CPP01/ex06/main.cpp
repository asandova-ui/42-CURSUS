/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:19:02 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 14:28:54 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"



int main( int ac, char **av ) {

    if (ac != 2) {
        return (std::cout << "Usage: ./harlFilter \"level\"\n", EXIT_FAILURE);
    }
    std::string input = av[1];
    Harl        harl;

    harl.complain(input);

    return EXIT_SUCCESS;
}