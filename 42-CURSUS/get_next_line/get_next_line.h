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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_storage
{
	char			*storage;
	size_t			length;
}					t_fd_storage;

char				*custom_free(char **str);
char				*free_stored_line(t_fd_storage *fd_storage);
char				*ft_get_line(t_fd_storage *fd_storage);
char				*read_file(int fd, t_fd_storage *fd_storage);
char				*get_next_line(int fd);

char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(const char *s1);

size_t				ft_strlen(const char *str);

#endif