/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:01:25 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 18:01:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

int	ft_integer(const char *ptr, va_list args)
{
    char	*value;
	int		n;
	int		length;

	n = va_arg(args, int);
    value = ft_itoa(n);
	ft_putstr(value);
	length = ft_strlen(value);
	free(value);
	return (length);
}