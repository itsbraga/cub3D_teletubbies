/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:47:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/09 13:43:34 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__has_all_textures(t_textures *tex)
{
	return (tex->north && tex->south && tex->west && tex->east);
}

void	process_texture_lines(char *line, t_textures *tex)
{
	fill_textures_paths(line, tex);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		tex->imgs[NO] = xpm_to_mlx_img(tex->north);
		s_data()->feature_filled++;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		tex->imgs[SO] = xpm_to_mlx_img(tex->south);
		s_data()->feature_filled++;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		tex->imgs[WE] = xpm_to_mlx_img(tex->west);
		s_data()->feature_filled++;
	}
	else
	{
		tex->imgs[EA] = xpm_to_mlx_img(tex->east);
		s_data()->feature_filled++;
	}
	if (__has_all_textures(tex) == true && check_textures_paths(tex) == FAILURE)
		clean_exit(FAILURE);
}

static bool	__has_all_bonus_textures(t_textures *tex)
{
	return (tex->floor && tex->ceiling && tex->door);
}

void	process_bonus_texture_lines(char *line, t_textures *tex)
{
	fill_bonus_textures_paths(line, tex);
	if (line[0] == 'F')
	{
		tex->imgs[F] = xpm_to_mlx_img(tex->floor);
		s_data()->feature_filled++;
	}
	else if (line[0] == 'C')
	{
		tex->imgs[C] = xpm_to_mlx_img(tex->ceiling);
		s_data()->feature_filled++;
	}
	else if (line[0] == 'D')
	{
		tex->imgs[D] = xpm_to_mlx_img(tex->door);
		s_data()->feature_filled++;
	}
	if (__has_all_bonus_textures(tex) == true
		&& check_bonus_textures_paths(tex) == FAILURE)
		clean_exit(FAILURE);
}
