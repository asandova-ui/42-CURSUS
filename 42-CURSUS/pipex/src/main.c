/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:57 by asandova          #+#    #+#             */
/*   Updated: 2024/04/26 12:38:26 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../printf/includes/ft_printf.h"
#include "../printf/libft/libft.h"

void	find_execs(char *cmd, char **envp)
{
	int		i;
	char	**command;
	char	**paths;
	char	*ubication;

	command = ft_split(cmd, ' ');
	paths = splitting_paths(envp);
	if (paths == NULL)
		custom_error("Error: no PATH", 1);
	i = 0;
	while (paths[i])
	{
		ubication = ft_strjoin_3args(paths[i], '/', command[0]);
		if (access(ubication, F_OK) == 0)
		{
			if (execve(ubication, command, NULL) == -1)
				custom_error("ERROR", 1);
		}
		free(ubication);
		i++;
	}
	custom_free(command);
	custom_free(paths);
	custom_error("ERROR", 1);
}

void	first_command(int *fd, char **argv, char **envp)
{
	int	f_in;

	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
	{
		custom_error("Error(input)", 1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		custom_error("ERROR (dup2 stdout)", 1);
	}
	if (dup2(f_in, STDIN_FILENO) == -1)
	{
		custom_error("ERROR (dup2 stdin)", 1);
	}
	close(fd[0]);
	close(f_in);
	close(fd[1]);
	find_execs(argv[2], envp);
}

void	seccond_command(int *fd, char **argv, char **envp)
{
	int	f_out;

	f_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (f_out < 0)
	{
		custom_error("Error(output)", 1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		custom_error("ERROR (dup2 stdin)", 1);
	}
	if (dup2(f_out, STDOUT_FILENO) == -1)
	{
		custom_error("ERROR (dup2 stdout)", 1);
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
		custom_error("Error en el pipe", 1);
	cpid = fork();
	if (cpid == -1)
		custom_error("Error con el fork", 1);
	if (cpid == 0)
		first_command(fd, argv, envp);
	cpid2 = fork();
	if (cpid2 == -1)
		custom_error("Error con el fork", 1);
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
		custom_error("Error: numero de argumentos incorrecto", 0);
	pipex(argv, envp);
	return (0);
}
