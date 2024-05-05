/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:57 by asandova          #+#    #+#             */
/*   Updated: 2024/05/05 21:22:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../printf/includes/ft_printf.h"
#include "../printf/libft/libft.h"

/*void	find_execs(char *cmd, char **envp)
{
	int		i;
	char	**command;
	char	**paths;
	char	*ubication;

	command = ft_split(cmd, ' ');
	paths = splitting_paths(envp);
	if (paths == NULL)
	{
		if (access(command[0], X_OK) == 0)
		{
			if (execve(command[0], command, envp) == -1)
				custom_error("ERROR", errno);
		}
		else
			custom_error("ERROR: comando no encontrado o no ejecutable", 127);
	}
	i = 0;
	while (paths[i])
	{
		ubication = ft_strjoin_3args(paths[i], '/', command[0]);
		if (access(ubication, X_OK) == 0)
		{
			if (execve(ubication, command, envp) == -1)
				custom_error("ERROR", errno);
		}
		free(ubication);
		i++;
	}
	custom_free(command);
	custom_free(paths);
	custom_error("ERROR: comando no encontrado", 127);
}*/

void	execute_command(char **command, char **envp)
{
	if (access(command[0], X_OK) == 0)
	{
		if (execve(command[0], command, envp) == -1)
			custom_error("ERROR", errno);
	}
	else
		custom_error("ERROR: comando no encontrado o no ejecutable", 127);
}

void	execute_from_paths(char **command, char **paths, char **envp)
{
	int		i;
	char	*ubication;

	i = 0;
	while (paths[i])
	{
		ubication = ft_strjoin_3args(paths[i], '/', command[0]);
		if (access(ubication, X_OK) == 0)
		{
			if (execve(ubication, command, envp) == -1)
				custom_error("ERROR", errno);
		}
		free(ubication);
		i++;
	}
}

void	find_execs(char *cmd, char **envp)
{
	char	**command;
	char	**paths;

	command = ft_split(cmd, ' ');
	paths = splitting_paths(envp);
	if (paths == NULL)
		execute_command(command, envp);
	else
	{
		execute_from_paths(command, paths, envp);
		custom_free(paths);
	}
	custom_free(command);
	custom_error("ERROR: comando no encontrado", 127);
}

void	first_command(int *fd, char **argv, char **envp)
{
	int	f_in;

	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
		custom_error("Error(input)", errno);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		custom_error("ERROR (dup2 stdout)", errno);
	if (dup2(f_in, STDIN_FILENO) == -1)
		custom_error("ERROR (dup2 stdin)", errno);
	close(fd[0]);
	close(f_in);
	close(fd[1]);
	find_execs(argv[2], envp);
}

void	second_command(int *fd, char **argv, char **envp)
{
	int	f_out;

	f_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (access(argv[4], W_OK) != 0)
		custom_error("Error de permisos en el archivo de salida", 1);
	if (f_out < 0)
		custom_error("Error(output)", errno);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		custom_error("ERROR (dup2 stdin)", errno);
	if (dup2(f_out, STDOUT_FILENO) == -1)
		custom_error("ERROR (dup2 stdout)", errno);
	close(fd[1]);
	close(fd[0]);
	close(f_out);
	find_execs(argv[3], envp);
}
/*void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	cpid;
	pid_t	cpid2;
	int		status;
	int		exit_status;

	if (pipe(fd) == -1)
		custom_error("Error en el pipe", errno);
	cpid = fork();
	if (cpid == -1)
		custom_error("Error con el fork", errno);
	if (cpid == 0)
		first_command(fd, argv, envp);
	cpid2 = fork();
	if (cpid2 == -1)
		custom_error("Error con el fork", errno);
	if (cpid2 == 0)
		second_command(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(cpid2, &status, 0);
	waitpid(cpid, NULL, 0);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		exit(exit_status);
	}
	else
		custom_error("Error esperando al segundo proceso hijo", 1);
}*/
