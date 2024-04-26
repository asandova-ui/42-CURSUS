/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manorteg <manorteg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:06:02 by asandova          #+#    #+#             */
/*   Updated: 2023/08/27 23:34:54 by manorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alll.h"

void	print_dec(char *num, const t_map *map, int size);

int		print_lastname(const t_map *map, int len, int size);

void	print_20_to_90(const char *num, const t_map *map, int size);

void	print_unit(char *num, const t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strncmp(map[i].number, &num[0], 1) == 0)
		{
			ft_putstr(map[i].word);
			return ;
		}
		i++;
	}
}

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (0);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n /= 10;
		i--;
	}
	return (str);
}

void	print_number(char *num, t_map *map)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(num) + 1;
	while (--len > 0)
	{
		if (len >= 3 && num[0] != '0')
		{
			print_unit(num, map, 32);
			print_lastname(map, len, 32);
		}
		else if (num[0] != '0')
		{
			if (len == 2 && num[0] > '1')
				print_20_to_90(num, map, 32);
			else if (len == 2)
				return (print_dec(num, map, 32));
			else
				return (print_unit(num, map, 32));
		}
		if (num[1] != '0')
			write(1, " ", 1);
		num++;
	}
}

void	print_20_to_90(const char *num, const t_map *map, int size)
{
	int		i;
	char	*dec;

	i = 0;
	while (i < size)
	{
		dec = ft_charcat(num[0], '0');
		if (ft_strncmp(&map[i].number[0], dec, 2) == 0)
		{
			ft_putstr(map[i].word);
			break ;
		}
		i++;
		free(dec);
	}
}
