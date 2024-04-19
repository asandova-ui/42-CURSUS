/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:39:59 by asandova          #+#    #+#             */
/*   Updated: 2024/04/18 18:10:37 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include "ft_printf/includes/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	custom_error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

char	**splitting_paths(char *envp[])
{
	int		it;
	char	**paths;

	it = 0;
	while (envp[it])
	{
		if (!ft_strncmp(envp[it], "PATH=", 5))
		{
			paths = ft_split(envp[it] + 5, ':');
			return (paths);
		}
		it++;
	}
	return (NULL);
}

char	*ft_strjoin_mod(char const *s1, char connector, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		str[x++] = s1[y++];
	str[x++] = connector;
	y = 0;
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	return (str);
}

void	custom_free(char **free_me)
{
	int		it;

	it = 0;
	while (free_me[it])
	{
		free(free_me[it]);
		it++;
	}
	free(free_me);
}
