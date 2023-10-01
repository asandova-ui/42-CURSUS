/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:29:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 13:29:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_storage	*custom_free(t_fd_storage *fd_storage)
{
	free(fd_storage->storage);
	fd_storage->storage = NULL;
	fd_storage->length = 0;
	free(fd_storage);
	return (NULL);
}

t_fd_storage	*free_stored_line(t_fd_storage *fd_storage)
{
	t_fd_storage	*new_storage;
	char			*ptr;
	int				len;

	ptr = ft_strchr(fd_storage->storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (custom_free(fd_storage));
	}
	else
		len = ptr - fd_storage->storage + 1;
	if (!fd_storage->storage[len])
		return (custom_free(fd_storage));
	new_storage = (t_fd_storage *)malloc(sizeof(t_fd_storage));
	if (!new_storage)
		return (NULL);
	new_storage->storage = ft_substr(fd_storage->storage, len, fd_storage->length - len);
	custom_free(fd_storage);
	if (!new_storage->storage)
	{
		free(new_storage);
		return (NULL);
	}
	new_storage->length = ft_strlen(new_storage->storage);
	return (new_storage);
}

t_fd_storage	*ft_get_line(t_fd_storage *fd_storage)
{
	t_fd_storage	*line;
	char			*ptr;
	int				len;

	ptr = ft_strchr(fd_storage->storage, '\n');
	if (!ptr)
		len = (int)fd_storage->length;
	else
		len = ptr - fd_storage->storage + 1;
	line = (t_fd_storage *)malloc(sizeof(t_fd_storage));
	if (!line)
		return (NULL);
	line->storage = ft_substr(fd_storage->storage, 0, len);
	if (!line->storage)
	{
		free(line);
		return (NULL);
	}
	line->length = ft_strlen(line->storage);
	return (line);
}

t_fd_storage	*read_file(int fd, t_fd_storage *fd_storage)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (custom_free(fd_storage));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(fd_storage->storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			fd_storage->storage = ft_strjoin(fd_storage->storage, buffer);
			fd_storage->length = ft_strlen(fd_storage->storage);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (custom_free(fd_storage));
	return (fd_storage);
}

char	*get_next_line(int fd)
{
	static t_fd_storage	*fd_storage;
	char				*line;

	if (fd < 0)
		return (NULL);
	if (!fd_storage || !ft_strchr(fd_storage->storage, '\n'))
		fd_storage = read_file(fd, fd_storage);
	if (!fd_storage)
		return (NULL);
	line = ft_get_line(fd_storage)->storage;
	if (!line)
		return (custom_free(fd_storage));
	fd_storage = free_stored_line(fd_storage);
	return (line);
}