/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:52:10 by asandova          #+#    #+#             */
/*   Updated: 2024/04/18 18:04:19 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

void	custom_error(char *str);
void	custom_free(char **free_me);
char	*ft_strjoin_mod(char const *s1, char connector, char const *s2);
char	**splitting_paths(char *envp[]);

#endif