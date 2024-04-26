/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:21:40 by asandova          #+#    #+#             */
/*   Updated: 2023/08/10 19:18:22 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	cif_moresig;
	int	cif2_moresig;
	int	cif3_moresig;

	cif_moresig = '0';
	while (cif_moresig <= '7')
	{
		cif2_moresig = cif_moresig +1;
		while (cif2_moresig <= '8')
		{
			cif3_moresig = cif2_moresig +1;
			while (cif3_moresig <= '9')
			{
				write(1, &cif_moresig, 1);
				write(1, &cif2_moresig, 1);
				write(1, &cif3_moresig, 1);
				cif3_moresig ++;
				if (cif_moresig != '7')
					write(1, ", ", 2);
			}
			cif2_moresig ++;
		}
		cif_moresig ++;
	}
}
