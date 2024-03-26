/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:55:18 by marvin            #+#    #+#             */
/*   Updated: 2024/03/21 18:55:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void start_prog(char **argv);
{
    
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_printf("%s", "Error, no se ha introducido mapa");
        return (0);
    }
    if (check_extension(argv[1]) == 1)
        start_prog(argv);
    return(0);
}