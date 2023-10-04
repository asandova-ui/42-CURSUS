/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:44:28 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 12:59:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("archivo_prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	while (i < 100)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			return (0);
		}
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
