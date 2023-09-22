/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:04:53 by marvin            #+#    #+#             */
/*   Updated: 2023/09/22 11:04:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    if (s1 == '\0' || set == '\0')
		return (NULL);
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1[start]);
	if (end)
	{
		while (s1[start + end - 1] && ft_strchr(set, s1[start + end - 1]))
			end--;
	}
	return (ft_substr(s1, start, end));
}