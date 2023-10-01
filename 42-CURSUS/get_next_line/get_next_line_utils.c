/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:29:21 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 13:29:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

char	*ft_strjoin(t_fd_storage *s1, char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1->storage)
	{
		s1->storage = (char *)malloc(sizeof(char));
		if (!s1->storage)
			return (NULL);
		s1->storage[0] = '\0';
	}
	str = malloc(sizeof(char) * (s1->length + ft_strlen(s2) + 1));
	if (!str)
		return (custom_free(s1));
	i = -1;
	while (s1->storage[++i])
		str[i] = s1->storage[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1->storage);
	s1->storage = str;
	s1->length = s1->length + ft_strlen(s2);
	return (s1->storage);
}

size_t	ft_strlen(t_fd_storage *str)
{
	return (str ? str->length : 0);
}

char	*ft_substr(t_fd_storage *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str->storage)
		return (NULL);
	if (start > str->length)
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (str->length - start < len)
		len = str->length - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < str->length && i < len && str->storage[start])
		res[i++] = str->storage[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(t_fd_storage *str, int c)
{
	int	i;

	if (!str->storage)
		return (NULL);
	i = -1;
	while (str->storage[++i])
		if (str->storage[i] == (char)c)
			return (&(str->storage[i]));
	if (str->storage[i] == (char)c)
		return (&(str->storage[i]));
	return (0);
}

char	*ft_strdup(t_fd_storage *str)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (str->length + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (str->storage[++i])
		ret[i] = str->storage[i];
	ret[i] = '\0';
	return (ret);
}
