/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:43:48 by asandova          #+#    #+#             */
/*   Updated: 2023/09/29 18:29:06 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *format, ...)
{
	int			chars_written;
	va_list		args;
	const char	*ptr;

	va_start(args, format);
	ptr = format;
	va_start(args, format);
	chars_written = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			chars_written += format_manager(ptr, args);
		}
		else
		{
			ft_putstr_fd((char *)ptr, 1);
			chars_written++;
		}
		ptr++;
	}
	va_end(args);
	return (chars_written);
}

int	format_manager(const char *ptr, va_list args)
{
	if (*ptr == 'd' || *ptr == 'i')
		return (print_integer(args, 1));
	else if (*ptr == 'u')
		return (print_nosign(args, 1));
	else if (*ptr == 'x')
		return (print_minushex(args, 1));
	else if (*ptr == 'X')
		return (print_mayushex(args, 1));
	else if (*ptr == 'c')
		return (print_character(args, 1));
	else if (*ptr == 's')
		return (print_string(args, 1));
	else if (*ptr == 'p')
		return (print_ptrhexa(args, 1));
	else
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
}
