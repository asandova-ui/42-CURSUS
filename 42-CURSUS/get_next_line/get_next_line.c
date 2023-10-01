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

void	update_rest(char **line, char **rest)
{
	char	*newline;
	char	*temp;

	if (!*rest)
		return;

	newline = ft_strchr(*rest, '\n');
	if (newline)
	{
		*rest = ft_strdup(newline + 1);
		if (!*rest)
			return; // Manejar error de asignación de memoria
		temp = ft_substr(*line, 0, ft_strlen(*line) - ft_strlen(newline + 1));
		free(*line);
		if (!temp)
		{
			free(*rest);
			*rest = NULL;
			return; // Manejar error de asignación de memoria
		}
		*line = temp;
	}
	else
	{
		free(*rest);
		*rest = NULL;
	}
}


char	*read_line(int fd, char **rest, char *buffer, int *bytes_read)
{
	char	*line;
	char	*temp;

	line = ft_strdup(*rest);
	while (!ft_strchr(*rest, '\n') && (*bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[*bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		if (!temp)
			return (NULL);
		line = temp;
	}
	if (*bytes_read == -1)
	{
		free(line);
		return (NULL); // Manejar error de lectura
	}
	update_rest(&line, rest);
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	line = read_line(fd, &rest, buffer, &bytes_read);

	free(buffer);
	if (bytes_read == -1)
		return (NULL);
	return (line);
}