/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:52:10 by asandova          #+#    #+#             */
/*   Updated: 2024/05/05 21:31:49 by marvin           ###   ########.fr       */
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
# include <sys/wait.h>
# include <errno.h>

typedef struct s_fork_args
{
	int		*fd;
	char	**argv;
	char	**envp;
	int		is_first;
}		t_fork_args;

void	custom_error(const char *msg, int code);
void	custom_free(char **free_me);
char	*ft_strjoin_3args(char const *s1, char connector, char const *s2);
char	**splitting_paths(char *envp[]);
void	first_command(int *fd, char **argv, char **envp);
void	second_command(int *fd, char **argv, char **envp);
#endif