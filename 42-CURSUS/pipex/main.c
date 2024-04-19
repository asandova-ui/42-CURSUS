/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:57 by asandova          #+#    #+#             */
/*   Updated: 2024/04/18 18:09:52 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include "ft_printf/includes/ft_printf.h"
#include "ft_printf/libft/libft.h"

void	find_execs(char *cmd, char **envp)
{
	int		it;
	char	**command;
	char	**paths;
	char	*the_way;

	command = ft_split(cmd, ' ');
	paths = splitting_paths(envp);
	if (paths == NULL)
		custom_error("Error: no PATH");
	it = 0;
	while (paths[it])
	{
		the_way = ft_strjoin_mod(paths[it], '/', command[0]);
		if (access(the_way, F_OK) == 0)
		{
			if (execve(the_way, command, NULL) == -1)
				custom_error("ERROR");
		}
		free(the_way);
		it++;
	}
	custom_free(command);
	custom_free(paths);
	custom_error("ERROR");
}

void	first_command(int *fd, char **argv, char **envp)
{
	int	f_in;

	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
	{
		custom_error("Error(input)");
	}
	if (dup2(fd[1], 1) == -1)
	{
		close(f_in);
		custom_error("ERROR (dup2 stdout)");
	}
	if (dup2(f_in, 0) == -1)
	{
		close(f_in);
		custom_error("ERROR (dup2 stdin)");
	}
	close(fd[0]);
	close(fd[1]);
	close(f_in);
	find_execs(argv[2], envp);
}

void	seccond_command(int *fd, char **argv, char **envp)
{
	int	f_out;

	f_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (f_out < 0)
	{
		custom_error("Error(output)");
	}
	if (dup2(fd[0], 0) == -1)
	{
		close(f_out);
		custom_error("ERROR (dup2 stdin)");
	}
	if (dup2(f_out, 0) == -1)
	{
		close(f_out);
		custom_error("ERROR (dup2 stdout)");
	}
	close(fd[1]);
	close(fd[0]);
	close(f_out);
	find_execs(argv[3], envp);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	cpid;
	pid_t	cpid2;

	if (pipe(fd) == -1)
		custom_error("Error en el pipe");
	cpid = fork();
	if (cpid == -1)
		custom_error("Error con el fork");
	if (cpid == 0)
		first_command(fd, argv, envp);
	cpid2 = fork();
	if (cpid2 == -1)
		custom_error("Error con el fork");
	if (cpid2 == 0)
		seccond_command(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(cpid, NULL, 0);
	waitpid(cpid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		custom_error("Error: numero de argumentos incorrecto");
	pipex(argv, envp);
	return (0);
}
