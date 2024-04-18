/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_highhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:38:32 by asandova          #+#    #+#             */
/*   Updated: 2024/04/18 15:03:18 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"

int	print_mayushex(va_list args, int fd)
{
	char	*value;
	int		n;
	int		length;

	n = va_arg(args, unsigned int);
	value = ft_itoa_base(n, "0123456789ABCDEF");
	ft_putstr_fd(value, fd);
	length = ft_strlen(value);
	free((void *)value);
	return (length);
}
