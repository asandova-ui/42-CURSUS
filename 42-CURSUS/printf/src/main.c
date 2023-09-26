/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:09:22 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 18:09:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../includes/printf.h"

int main(void)
{
    int cant;

    cant = ft_printf("%d", 123);
    printf("Numero de caracteres que escribo: %d", cant);
    return (0);
}