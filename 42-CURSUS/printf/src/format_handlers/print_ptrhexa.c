/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:27:27 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 17:02:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_hex(uintptr_t n, int fd)
{
	const char	*hex_chars = "0123456789abcdef";

	if (n >= 16)
		ft_putnbr_hex(n / 16, fd);
	ft_putchar_fd(hex_chars[n % 16], fd);
}

int	print_ptrhexa(va_list args, int fd)
{
	uintptr_t	ptr_value = va_arg(args, uintptr_t);
	int			chars_written = 0;

	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	chars_written += 2;
	ft_putnbr_hex(ptr_value, fd);
	while (ptr_value != 0)
	{
		ptr_value /= 16;
		chars_written++;
	}
	return (chars_written);
}
