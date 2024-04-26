/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:52:11 by asandova          #+#    #+#             */
/*   Updated: 2023/08/31 12:52:21 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_abs.h"

int	main(void)
{
	int	index;

	index = -5;
	while (index < 5)
	{
		printf("macros::abs(%d) = %d\n", index, ABS(index));
		index++;
	}
}
