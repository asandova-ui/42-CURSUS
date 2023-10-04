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


char	*remix_free(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

char	*line_keep(t_fd_storage *fd_storage)
{
	char	*temp_st;
	char	*ptr;
	int		lo;

	ptr = ft_strchr(fd_storage->storage, '\n');
	if (!ptr)
	{
		temp_st = NULL;
		return (remix_free(&fd_storage->storage));
	}
	else
		lo = ptr - fd_storage->storage + 1;
	if (!fd_storage->storage[lo])
		return (remix_free(&fd_storage->storage));
	temp_st = ft_substr(fd_storage->storage, 0, ft_strlen(fd_storage->storage) - lo);
	remix_free(&fd_storage->storage);
	if (!temp_st)
		return (NULL);
	return (temp_st);
}

char	*line_getting(t_fd_storage *fd_storage)
{
	char	*returning_line;
	char	*sto;
	int		lo;

	sto = ft_strchr(fd_storage->storage, '\n');
	if (!sto)
		lo = (int)ft_strlen(fd_storage->storage);
	else
		lo = sto - fd_storage->storage + 1;
	returning_line = ft_substr(fd_storage->storage, 0, lo);
	if (!returning_line)
		return (NULL);
	return (returning_line);
}

char	*base_file_reading(int fd, t_fd_storage *fd_storage)
{
	int		lo_bytes;
	char	*buff;

	lo_bytes = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (remix_free(&fd_storage->storage));
	buff[0] = '\0';
	while (lo_bytes > 0 && !ft_strchr(fd_storage->storage, '\n'))
	{
		lo_bytes = read(fd, buff, BUFFER_SIZE);
		if (lo_bytes > 0)
		{
			buff[lo_bytes] = '\0';
			fd_storage->storage = ft_strjoin(fd_storage->storage, buff);
		}
	}
	free(buff);
	if (lo_bytes == -1)
		return (remix_free(&fd_storage->storage));
	return (fd_storage->storage);
}

char	*get_next_line(int fd)
{
	static t_fd_storage	fd_storage;
	char				*line;

	if (fd < 0)
		return (NULL);
	if (!fd_storage.storage || !ft_strchr(fd_storage.storage, '\n'))
		fd_storage.storage = base_file_reading(fd, &fd_storage);
	if (!fd_storage.storage)
		return (NULL);
	line = line_getting(&fd_storage);
	if (!line)
		return (remix_free(&fd_storage.storage));
	fd_storage.storage = line_keep(&fd_storage);
	if (!ft_strchr(line, '\n'))
	{
		line[ft_strlen(line)] = '\0';
		return (line);
	}
	return (line);
}

/*char	*remix_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*line_keep(t_fd_storage *fd_storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(fd_storage->storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (remix_free(&fd_storage->storage));
	}
	else
		len = ptr - fd_storage->storage + 1;
	if (!fd_storage->storage[len])
		return (remix_free(&fd_storage->storage));
	new_storage = ft_substr(fd_storage->storage, len, ft_strlen(fd_storage->storage) - len);
	remix_free(&fd_storage->storage);
	if (!new_storage)
		return (NULL);
	fd_storage->storage = new_storage;
	fd_storage->length -= len;
	return (new_storage);
}

char	*line_getting(t_fd_storage *fd_storage)
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

char	*base_file_reading(int fd, t_fd_storage *fd_storage)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (remix_free(&buffer));
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
		return (remix_free(&fd_storage->storage));
	return (fd_storage->storage);
}


char	*get_next_line(int fd)
{
	static t_fd_storage	fd_storage;
	char				*line;

	fd_storage.storage = NULL;
	fd_storage.length = 0;
	if (fd < 0)//fd incorrecto
		return (NULL);
	if (fd_storage.storage == NULL|| !ft_strchr(fd_storage.storage, '\n'))
		fd_storage.storage = base_file_reading(fd, &fd_storage);
	if (!fd_storage.storage)
		return (NULL);
	line = line_getting(&fd_storage);
	if (!line)
		return (remix_free(&fd_storage.storage));
	fd_storage.storage = line_keep(&fd_storage);
	return (line);
}
*/