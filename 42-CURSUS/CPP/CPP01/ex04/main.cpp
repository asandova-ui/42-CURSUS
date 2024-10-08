/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:56:37 by alonso            #+#    #+#             */
/*   Updated: 2024/10/08 14:13:30 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceText.hpp"

int main ( int ac, char **av )
{
    if (ac != 4) {
        std::cerr << "Pon: ./ReplaceName <filename> <to_find> <replace>." << std::endl;
        return EXIT_FAILURE;
    } else {
        ReplaceText   rep2(av[1]);
        rep2.replace(av[2], av[3]);
    }
    return EXIT_SUCCESS;
}