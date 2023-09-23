/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:27:13 by marvin            #+#    #+#             */
/*   Updated: 2023/09/18 19:27:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t 	new_len;

	new_len = ft_strlen(s);
	if (*s == '\0')
		return(NULL);
	if (new_len < start)
		return (NULL);
	if(!(str = (char *)malloc(sizeof(char)*(len + 1))))
		return (NULL);
	new_len = 0;
	while (new_len < len)
	{
		str[new_len] = s[start];
		new_len ++;
		start ++;
	}
	str[new_len] = '\0';
	return (str);
}
