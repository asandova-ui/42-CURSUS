/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:56:00 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 17:56:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)s1;
	s = (char *)s2;
	i = 0;
	while (n--)
	{
		if (d[i] != s[i])
			return ((unsigned char)d[i] - (unsigned char)s[i]);
		i++;
	}
	return (0);
}
