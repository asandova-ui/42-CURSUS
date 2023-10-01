/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:29:27 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 13:29:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_fd_storage
{
	char			*storage;
	size_t			length;
}					t_fd_storage;

char	*custom_free(t_fd_storage *str);
char	*free_stored_line(t_fd_storage *fd_storage);
char	*ft_get_line(t_fd_storage *fd_storage);
char	*read_file(int fd, t_fd_storage *fd_storage);
char	*get_next_line(int fd);

char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);

#endif