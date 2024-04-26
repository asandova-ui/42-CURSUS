/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:21:11 by asandova          #+#    #+#             */
/*   Updated: 2023/08/17 15:53:22 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	isspace_detect(char a);

int	ft_atoi(char *str)
{
	int	i;
	int	cross;
	int	num;

	i = 0;
	cross = 1;
	num = 0;
	while (str[i] != '\0')
	{
		if (isspace_detect(str[i]) == '0')
		{
			while ((str[i] == '+') || (str[i] == '-'))
			{
				if (str[i] == '-')
					cross = -cross;
				i ++;
			}
			i --;
			while (str[++i] >= '0' && str[i] <= '9' && str[i])
				num = (num * 10) + (str[i] - '0');
			return (num * cross);
		}
	i ++;
	}
	return (0);
}

char	isspace_detect(char a)
{
	char	r;

	r = '0';
	if (a == 32 || (a <= 13 && a >= 9))
		r = '1';
	return (r);
}

/*int		main(void)
{
	char *str = " ---+--+1234ab567";
	int	num;
	num = ft_atoi(str);
	printf ("%d", num);
	return (0);
}*/
