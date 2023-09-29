/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:57:52 by marvin            #+#    #+#             */
/*   Updated: 2023/09/29 18:28:34 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include "../../libft/libft.h"

int	print_string(va_list args, int fd)
{
	char	*value;
	int		length;

	value = va_arg(args, char *);
	ft_putstr_fd(value, fd);
	length = ft_strlen(value);
	return (length);
}
