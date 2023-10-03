/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:43:54 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 13:30:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*custom_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*free_stored_line(t_fd_storage *fd_storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(fd_storage->storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (custom_free(&fd_storage->storage));
	}
	else
		len = ptr - fd_storage->storage + 1;
	if (!fd_storage->storage[len])
		return (custom_free(&fd_storage->storage));
	new_storage = ft_substr(fd_storage->storage, len, ft_strlen(fd_storage->storage) - len);
	custom_free(&fd_storage->storage);
	if (!new_storage)
		return (NULL);
	/*fd_storage->storage = new_storage;
	fd_storage->length -= len;*/
	return (new_storage);
}

char	*ft_get_line(t_fd_storage *fd_storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(fd_storage->storage, '\n');
	if (!ptr)
		len = (int)ft_strlen(fd_storage->storage);
	else
		len = ptr - fd_storage->storage + 1;
	line = ft_substr(fd_storage->storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_file(int fd, t_fd_storage *fd_storage)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (custom_free(&buffer));
	fd_storage->storage = ft_strdup("");
	while (bytes_read > 0 && !ft_strchr(fd_storage->storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			fd_storage->storage = ft_strjoin(fd_storage->storage, buffer);
			fd_storage->length += bytes_read;
    	}
	}
	free(buffer);
	if (bytes_read == -1 || fd_storage->length == 0)
		return (custom_free(&fd_storage->storage));
	return (fd_storage->storage);
}


char	*get_next_line(int fd)
{
	static t_fd_storage	fd_storage;
	char				*line;

	/*fd_storage.storage = NULL;
	fd_storage.length = 0;*/
	if (fd < 0)//fd incorrecto
		return (NULL);
	if (!fd_storage.storage || !ft_strchr(fd_storage.storage, '\n'))
		fd_storage.storage = read_file(fd, &fd_storage);
	if (!fd_storage.storage)
		return (NULL);
	line = ft_get_line(&fd_storage);
	if (!line)
		return (custom_free(&fd_storage.storage));
	fd_storage.storage = free_stored_line(&fd_storage);
	return (line);
}
