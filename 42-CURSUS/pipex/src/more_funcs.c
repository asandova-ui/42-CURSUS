/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:09:42 by marvin            #+#    #+#             */
/*   Updated: 2024/05/05 21:09:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../printf/includes/ft_printf.h"
#include "../printf/libft/libft.h"

void	handle_fork(pid_t *cpid, t_fork_args *args)
{
	*cpid = fork();
	if (*cpid == -1)
		custom_error("Error con el fork", errno);
	if (*cpid == 0)
	{
		if (args->is_first)
			first_command(args->fd, args->argv, args->envp);
		else
			second_command(args->fd, args->argv, args->envp);
	}
}

void	close_pipes(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	wait_for_children(pid_t cpid, pid_t cpid2)
{
	int	status;
	int	exit_status;

	waitpid(cpid2, &status, 0);
	waitpid(cpid, NULL, 0);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		exit(exit_status);
	}
	else
		custom_error("Error esperando al segundo proceso hijo", 1);
}

void	pipex(char **argv, char **envp)
{
	int			fd[2];
	pid_t		cpid;
	pid_t		cpid2;
	t_fork_args	args_first;
	t_fork_args	args_second;

	args_first.fd = fd;
	args_first.argv = argv;
	args_first.envp = envp;
	args_first.is_first = 1;
	args_second.fd = fd;
	args_second.argv = argv;
	args_second.envp = envp;
	args_second.is_first = 0;
	if (pipe(fd) == -1)
		custom_error("Error en el pipe", errno);
	handle_fork(&cpid, &args_first);
	handle_fork(&cpid2, &args_second);
	close_pipes(fd);
	wait_for_children(cpid, cpid2);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		custom_error("Error: numero de argumentos incorrecto", 1);
	pipex(argv, envp);
	return (0);
}
