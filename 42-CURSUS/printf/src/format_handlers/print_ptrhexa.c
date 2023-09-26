/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:27:27 by marvin            #+#    #+#             */
/*   Updated: 2023/09/26 17:27:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/Libft/libft.h"

print_ptrhexa(const char *ptr, va_list args, int fd)
{
    void *value;
    char    *hex_value;
    int     length;
    
    value = va_arg(args, void *);
    hex_value = ft_itoa_base((unsigned long)value, "0123456789abcdef");
    ft_putstr_fd(hex_value, fd);
    length = ft_strlen(hex_value);
    free(hex_value);
    return (length);
}