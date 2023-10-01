/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:59:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 11:59:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(int fd, char **remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (*remainder)
		{
			temp = *remainder;
			*remainder = ft_strjoin(temp, buffer);
			free(temp);
		}
		else
			*remainder = ft_strjoin("", buffer);
		if (ft_strchr(*remainder, '\n'))
			return (1);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	bytes_read = read_line(fd, &remainder);
	if (bytes_read < 0)
		return (NULL);
	if (!bytes_read && !remainder)
		return (NULL);
	line = ft_strchr(remainder, '\n');
	if (line)
		*line++ = '\0';
	temp = remainder;
	remainder = (line) ? ft_strdup(line) : NULL;
	return (temp);
}
