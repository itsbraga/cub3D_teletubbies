/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:26:18 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 03:40:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__is_valid_extension(char *filename)
{
    size_t len;

    if (filename == NULL)
        return (false);
    len = ft_strlen(filename);
    if (len < 4)
        return (false);
    if (ft_strncmp(filename + (len - 4), ".xpm", 4) != 0)
        return (false);
    return (true);
}

static bool __is_not_directory(const char *path)
{
	int	fd;
	
	fd = open(path, __O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (false);
	}
	return (true);
}

static void	__check_open_error(const char *arg)
{
	if (__is_not_directory(arg) == false)
		err_msg(NULL, strerror(EISDIR));
	else if (errno == EACCES)
		err_msg(NULL, strerror(EACCES));
	else if (errno == ENOENT)
		err_msg(NULL, strerror(ENOENT));
	else
		err_msg(NULL, strerror(errno));
}

static int	__check_xpm_file(char *arg)
{
	int	fd;

	if (__is_valid_extension(arg) == false)
	{
		err_msg(NULL, ERR_XPM_EXT);
		exit(FAILURE);
	}
	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		__check_open_error(arg);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	check_textures_paths(t_textures *tex)
{
	if (__check_xpm_file(tex->north) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->south) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->west) == FAILURE)
		return (FAILURE);
	if (__check_xpm_file(tex->east) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
