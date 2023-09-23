/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:20:47 by marvin            #+#    #+#             */
/*   Updated: 2023/09/22 11:20:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_itoa(int n)
{
	char	*r;
	char	s;
	size_t	len;
	int		i;

	if (n < 0)
		s = -1;
	else
		s = 1;
	len = 2 + (n < 0);
	i = n;
	while ((n = n / 10))
		len++;
	(r = (char *)malloc(sizeof(char) * len--));
	if (!r)
		return (NULL)a;
	r[len--] = '\0';
	r[len--] = s * (i % 10) + 48;
	while ((i = i / 10))
		r[len--] = s * (i % 10) + 48;
	if (s < 0)
		r[len] = '-';
	return (r);
}
