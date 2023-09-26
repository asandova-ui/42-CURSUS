/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:09:56 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 17:09:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	print_integer(const char *ptr, va_list args, int fd);
int	print_nosign(const char *ptr, va_list args, int fd);
int	print_mayushex(const char *ptr, va_list args, int fd);
int	print_minushex(const char *ptr, va_list args, int fd);
int	print_character(const char *ptr, va_list args, int fd);
int	print_string(const char *ptr, va_list args, int fd);
int print_ptrhexa(const char *ptr, va_list args, int fd);


char *ft_uitoa(unsigned int n);
char	*ft_itoa_base(unsigned int n, char *base);

#endif