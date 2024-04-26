/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 08:01:44 by asandova          #+#    #+#             */
/*   Updated: 2023/08/17 18:56:24 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] -(unsigned char)s2[i]);
		i ++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0'))
	{
		if (i < n)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

/*int	main(void)
{
	char *s1 = "hola buenas";
	char *s2 = "hola";
	int i;
	int num = 3;

	i = ft_strncmp(s1,s2,num);
	printf("%d",i);
	return 0;
}*/
