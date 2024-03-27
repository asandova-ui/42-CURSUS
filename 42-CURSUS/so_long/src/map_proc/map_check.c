/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:05:39 by marvin            #+#    #+#             */
/*   Updated: 2024/03/21 19:05:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../printf/libft/libft.h"

int check_extension(char *argv)
{
    int len;

    len = ft_strlen(argv);
    if (ft_strncmp(&argv[len - 4], ".ber", 4))
	{
		ft_putstr_fd("Error. Extensión incorrecta.\n", 1);
		return (-1);
	}
	return (0);
}