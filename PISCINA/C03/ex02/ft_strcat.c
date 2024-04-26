/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:26:54 by asandova          #+#    #+#             */
/*   Updated: 2023/08/17 19:09:56 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i ++;
	while (src[j] != '\0')
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

	ft_strcat(dest,src);
	printf ("%s",dest);
	return (0);
}*/
