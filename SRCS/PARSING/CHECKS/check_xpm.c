/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:26:18 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/13 00:59:53 by art3mis          ###   ########.fr       */
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
	else
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

static short	__check_xpm_file(char *arg)
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

short	check_textures_paths(t_textures *tex)
{
	if (__check_xpm_file(tex->north) == SUCCESS
		|| __check_xpm_file(tex->south) == SUCCESS
		|| __check_xpm_file(tex->west) == SUCCESS
		|| __check_xpm_file(tex->east) == SUCCESS)
		return (SUCCESS);
	else
		return (FAILURE);
}
