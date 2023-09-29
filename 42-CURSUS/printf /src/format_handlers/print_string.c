/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:57:52 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 16:57:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../libft/libft.h"

int	print_string(va_list args, int fd)
{
	const char	*value;
	int		length;

	value = va_arg(args, char*);
	ft_putstr_fd(value, fd);
	length = ft_strlen(value);
	return (length);
}