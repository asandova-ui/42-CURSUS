/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_nosign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:12:42 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 18:12:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../Libft/libft.h"

int	print_nosign(const char *ptr, va_list args, int fd)
{
    const char	*value;
	unsigned int		n;
	int lenght;

	n = va_arg(args, unsigned int);
    value = ft_uitoa(n);
	ft_putstr_fd(value, fd);
	lenght = ft_strlen(value);
	free(value);
	return (lenght);
}