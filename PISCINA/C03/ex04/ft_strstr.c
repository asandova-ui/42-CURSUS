/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:01:38 by asandova          #+#    #+#             */
/*   Updated: 2023/08/17 18:58:03 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*temp;

	temp = str;
	if (*to_find == '\0')
		return (str);
	while (*temp)
	{
		i = 0;
		if (*temp == to_find[0])
		{
			while (temp[i] == to_find[i] && to_find[i])
				i ++;
			if (to_find[i] == '\0')
				return (temp);
		}
		temp ++;
	}
	return (0);
}

/*int	main(void)
{
	char	*str = "mundoholaordenadores";
	char	*to_find = "hola";

	char *temp;

	temp = ft_strstr(str,to_find);
	printf ("%s",temp);
	return (0);
*/
