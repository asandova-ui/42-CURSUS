/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:09:22 by marvin            #+#    #+#             */
/*   Updated: 2023/09/29 18:28:52 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/printf.h"

int	main(void)
{
	int	cant;

	cant = ft_printf("%d", 123);
	printf("Numero de caracteres que escribo: %d", cant);
	return (0);
}
