/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:50:19 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 10:50:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


typedef struct	s_fd_list
{
	int				fd;
	t_fd_storage	fd_storage;
	struct s_fd_list	*next;
}				t_fd_list;

// Variable estática para almacenar la lista de fd
static t_fd_list	*fd_list = NULL;

char	*remix_free(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

static t_fd_storage	*get_fd_storage(int fd)
{
	t_fd_list	*current = fd_list;

	// Buscar la estructura correspondiente al fd
	while (current)
	{
		if (current->fd == fd)
			return &(current->fd_storage);
		current = current->next;
	}

	// Si no se encuentra, crear una nueva estructura y agregarla a la lista
	t_fd_list	*new_fd = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new_fd)
		return (NULL);
	new_fd->fd = fd;
	new_fd->fd_storage.storage = NULL;
	new_fd->next = fd_list;
	fd_list = new_fd;

	return &(new_fd->fd_storage);
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
	fd_storage->length = ft_strlen(fd_storage->storage);
	temp_st = ft_substr(fd_storage->storage, lo, fd_storage->length - lo);
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
	t_fd_storage	*fd_storage = get_fd_storage(fd);
	char			*line;

	if (fd < 0 || !fd_storage)
		return (NULL);
	if (!fd_storage->storage || !ft_strchr(fd_storage->storage, '\n'))
		fd_storage->storage = base_file_reading(fd, fd_storage);
	if (!fd_storage->storage)
		return (NULL);
	line = line_getting(fd_storage);
	if (!line)
		return (remix_free(&fd_storage->storage));
	fd_storage->storage = line_keep(fd_storage);
	if (!ft_strchr(line, '\n'))
	{
		line[ft_strlen(line)] = '\0';
		return (line);
	}
	return (line);
}