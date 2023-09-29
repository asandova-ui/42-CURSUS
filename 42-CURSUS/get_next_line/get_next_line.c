/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:43:54 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 11:43:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *custom_free(char **str)
{
    free(*str);
    *str = NULL;
    return (NULL);
}

static char *free_stored_line(t_fd_storage *fd_storage)
{
    char *new_storage;
    char *ptr;
    int len;

    ptr = ft_strchr(fd_storage->storage, '\n');
    if (!ptr)
        return (custom_free(&fd_storage->storage));
    else
        len = ptr - fd_storage->storage + 1;
    if (!fd_storage->storage[len])
        return (custom_free(&fd_storage->storage));
    new_storage = ft_strdup(fd_storage->storage + len);
    custom_free(&fd_storage->storage);
    if (!new_storage)
        return (NULL);
    fd_storage->storage = new_storage;
    fd_storage->length -= len;
    return (new_storage);
}

static char *ft_get_line(t_fd_storage *fd_storage)
{
    char *line;
    char *ptr;
    int len;

    ptr = ft_strchr(fd_storage->storage, '\n');
    if (!ptr)
        len = (int)fd_storage->length;
    else
        len = ptr - fd_storage->storage + 1;
    line = ft_substr(fd_storage->storage, 0, len);
    if (!line)
        return (NULL);
    return (line);
}

static char *read_file(int fd, t_fd_storage *fd_storage)
{
    int bytes_read;
    char buffer[BUFFER_SIZE + 1];

    bytes_read = 1;
    buffer[0] = '\0';
    while (bytes_read > 0 && !ft_strchr(fd_storage->storage, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0';
            char *new_storage = ft_strjoin(fd_storage->storage, buffer);
            if (!new_storage)
                return (custom_free(&fd_storage->storage));
            custom_free(&fd_storage->storage);
            fd_storage->storage = new_storage;
            fd_storage->length += bytes_read;
        }
    }
    if (bytes_read == -1)
        return (custom_free(&fd_storage->storage));
    return (fd_storage->storage);
}

char *get_next_line(int fd)
{
    static t_fd_storage fd_storage = {NULL, 0};
    char *line;

    if (fd < 0)
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
