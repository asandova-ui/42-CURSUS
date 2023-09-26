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
#include "../Libft/libft.h"

int	print_integer(const char *ptr, va_list args, int fd)
{
    const char	*value;
	int		n;
	int		length;

	n = va_arg(args, int);
    value = ft_itoa(n);
	ft_putstr_fd(value, fd);
	length = ft_strlen(value);
	free(value);
	return (length);
}