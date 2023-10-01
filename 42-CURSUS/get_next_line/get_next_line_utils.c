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

char *ft_strcat(char *dest, char *src)
{
    char *original_dest = dest;

    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return original_dest;
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char *ft_strndup(char *str, size_t n)
{
    size_t len = 0;
	size_t i = 0;

    while (len < n && str[len] != '\0') {
        len++;
    }
    char *result = (char *)malloc(len + 1);
    if (result == NULL) {
        return NULL;
    }
	while(i < len)
	{
		result[i] = str[i];
		i ++;
	}
    result[len] = '\0';
    return result;
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
	if (str[i] == (char)c)
		return (&((char *)str)[i]);
	return (0);
}
