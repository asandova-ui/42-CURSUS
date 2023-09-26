/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mayushex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:38:32 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 18:38:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../Libft/libft.h"

int	print_mayushex(const char *ptr, va_list args, int fd)
{
    char	*value;
	int		n;
	int		length;

    n = va_arg(args, unsigned int);
	value = ft_itoa_base(n, "0123456789ABCDEF");
	ft_putstr_fd(value, fd);
	length = ft_strlen(value);
	free(value);
	return (length);
}