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
	custom_free(s1);
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(t_fd_storage *s1, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s1->storage)
		return (NULL);
	if (start > s1->length)
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (s1->length - start < len)
		len = s1->length - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < s1->length && i < len && s1->storage[start])
		res[i++] = s1->storage[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(t_fd_storage *s1, int c)
{
	int	i;

	if (!s1->storage)
		return (NULL);
	i = -1;
	while (s1->storage[++i])
		if (s1->storage[i] == (char)c)
			return (&((char *)s1->storage)[i]);
	if (s1->storage[i] == (char)c)
		return (&((char *)s1->storage)[i]);
	return (0);
}

char	*ft_strdup(t_fd_storage *s1)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (s1->length + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1->storage[++i])
		ret[i] = s1->storage[i];
	ret[i] = '\0';
	return (ret);
}
