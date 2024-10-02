/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alonso <alonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:14:43 by alonso            #+#    #+#             */
/*   Updated: 2024/09/28 18:02:33 by alonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

static bool	is_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

static bool	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

int	check_file(char *arg, bool cub)
{
	int	fd;

	if (is_dir(arg))
		return (custom_error(arg, ERR_FILE_IS_DIR, FAILURE));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (custom_error(arg, strerror(errno), FAILURE));
	close(fd);
	if (cub && !is_cub_file(arg))
		return (custom_error(arg, ERR_FILE_NOT_CUB, FAILURE));
	if (!cub && !is_xpm_file(arg))
		return (custom_error(arg, ERR_FILE_NOT_XPM, FAILURE));
	return (SUCCESS);
}
