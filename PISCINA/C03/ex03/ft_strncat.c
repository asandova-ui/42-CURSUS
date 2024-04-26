/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:52:01 by asandova          #+#    #+#             */
/*   Updated: 2023/08/17 19:16:48 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i ++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		j ++;
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int	main(void)
{
	char	dest[20] = "Hola";
	char	*src = "mundo";
	unsigned int	nb= 3;
	ft_strncat(dest,src,nb);
	printf ("%s",dest);
	return (0);
}*/
