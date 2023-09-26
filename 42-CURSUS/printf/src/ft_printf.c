/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:43:48 by asandova            #+#    #+#           */
/*   Updated: 2023/09/23 11:43:48 by asandova           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../includes/printf.h"

int ft_printf(const char *format, ...)
{
	int chars_written;
	va_list args;
	va_start(args, format);
	const char *ptr;

	ptr = format;
	va_start(args, format);
	chars_written = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr ++;
			chars_written += format_manager(ptr,args);
        }
		else
		{
			ft_putstr_fd(ptr, 1);
            chars_written++;
		}
		ptr ++;
	}
	va_end(args);
	return (chars_written);
}

int	format_manager(const char *ptr, va_list args)
{
	if (*ptr == 'd' || *ptr == 'i') //HECHA
	{
        return(print_integer(ptr, args, 1));
    } 
	else if (*ptr == 'u')//HECHA
	{
        return(print_nosign(ptr, args, 1));
    } 
	else if (*ptr == 'x') //HECHA
	{
        return(print_minushex(ptr, args, 1));
    } 
	else if (*ptr == 'X') //HECHA
	{
        return(print_mayushex(ptr, args, 1));
    } 
	else if (*ptr == 'c') //HECHA
	{
        return(print_character(ptr, args, 1));
    } 
	else if (*ptr == 's') //HECHA
	{
        return(print_string(ptr, args, 1));
    } 
	else if (*ptr == 'p') //HECHA
	{
        return(print_ptrhexa(ptr, args, 1));
    } 
	else //HECHO EL %
	{
        ft_putchar_fd('%', 1);
        return (1);
    }
}

