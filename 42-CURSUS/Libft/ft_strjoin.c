/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:12:45 by marvin            #+#    #+#             */
/*   Updated: 2023/09/22 10:12:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  size1;
    size_t  size2;
    size_t  new_len;
    char    *new_str;

    new_len = 0;
    size1 = ft_strlen(s1);
    size2 = ft_strlen(s2);
    if(*s1 == '\0' && *s2 == '\0')
        return (NULL);
    if(!(new_str=(char *)malloc(sizeof(char) * (size1 + size2 +1))))
        return (NULL);
    while (*s1)
    {
        new_str[new_len] = s1;
        s1 ++;
    }
    while (*s1)
    {
        new_str[new_len] = s2;
        s1 ++;
    }
    new_str[new_len] = '\0';
    return (new_len);
}