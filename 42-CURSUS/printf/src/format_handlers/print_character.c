/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:46:42 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 16:46:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../Libft/libft.h"

int	print_character(const char *ptr, va_list args, int fd)
{
	char	value;
	int		length;

	value = va_arg(args, int);
	ft_putchar_fd(value, fd);
	length = 1;
	return(length);
}