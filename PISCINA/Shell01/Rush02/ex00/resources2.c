/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:34:01 by asandova          #+#    #+#             */
/*   Updated: 2023/08/27 23:21:49 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alll.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && (*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

char	*ft_charcat(char dest, char src)
{
	char	*result;

	result = malloc(sizeof(char) * 3);
	if (result == NULL)
		return ("\0");
	result[0] = dest;
	result[1] = src;
	result[2] = '\0';
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
