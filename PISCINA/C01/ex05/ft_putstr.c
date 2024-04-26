/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:29:30 by asandova          #+#    #+#             */
/*   Updated: 2023/08/12 13:58:42 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
	{
		write(1, &str[k], 1);
		k ++;
	}
}

/*int	main(void)
{
	char	*str;

	str = "M0amaodou";
	ft_putstr(str);
	return (0);
}*/
