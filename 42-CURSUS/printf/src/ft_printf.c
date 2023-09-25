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

#include "../includes/libft.h"
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
			chars_written += format_manager(*ptr,args);
        }
		else
		{
			ft_putchar(*ptr);
            chars_written++;
		}
		ptr ++;
	}
	va_end(args);
}

int	format_manager(const char *ptr, va_list args)
{
	if (*ptr == 'd' || *ptr == 'i') //HECHA
	{
        return(print_integer(ptr, args));
    } 
	else if (*ptr == 'u')//HECHA
	{
        return(print_nosign(ptr, args));
    } 
	else if (*ptr == 'x') //hexa minuscula
	{
        int int_arg = va_arg(args, int);
        return(ft_putnbr(int_arg));
    } 
	else if (*ptr == 'X') //hexa maxus
	{
        int int_arg = va_arg(args, int);
        return(ft_putnbr(int_arg));
    } 
	else if (*ptr == 'c') //1 solo caracter
	{
        int int_arg = va_arg(args, int);
        return(ft_putnbr(int_arg));
    } 
	else if (*ptr == 's') //String
	{
        int int_arg = va_arg(args, int);
        return(ft_putnbr(int_arg));
    } 
	else if (*ptr == 'p') //void * se imprime en hexadecimal
	{
        int int_arg = va_arg(args, int);
        return(ft_putnbr(int_arg));
    } 
	else //imprime un porcentaje
	{
        ft_putchar('%');
        return (1);
    }
}

