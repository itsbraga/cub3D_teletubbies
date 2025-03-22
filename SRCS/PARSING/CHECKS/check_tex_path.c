/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:26:40 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 20:02:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_textures_paths(t_textures *tex)
{
	if (check_xpm_file(tex->north) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->south) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->west) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->east) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	check_bonus_textures_paths(t_textures *tex)
{
	if (check_xpm_file(tex->floor) == FAILURE)
		return (FAILURE);
	if (check_xpm_file(tex->ceiling) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
