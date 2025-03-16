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

void	process_texture_lines(char *line, t_textures *tex)
{
	fill_textures_paths(line, tex);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		tex->imgs[NO] = xpm_to_mlx_img(tex->north);
		printf("tex->imgs[NO] img_ptr: %p\n", tex->imgs[NO].img_ptr);
		s_data()->feature_filled++;
		// printf(BOLD ORANGE "data->feature_filled: %u\n\n" RESET, s_data()->feature_filled);
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		tex->imgs[SO] = xpm_to_mlx_img(tex->south);
		printf("tex->imgs[SO] img_ptr: %p\n", tex->imgs[SO].img_ptr);
		s_data()->feature_filled++;
		// printf(BOLD ORANGE "data->feature_filled: %u\n\n" RESET, s_data()->feature_filled);
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		tex->imgs[WE] = xpm_to_mlx_img(tex->west);
		printf("tex->imgs[WE] img_ptr: %p\n", tex->imgs[WE].img_ptr);
		s_data()->feature_filled++;
		// printf(BOLD ORANGE "data->feature_filled: %u\n\n" RESET, s_data()->feature_filled);
	}
	else
	{
		tex->imgs[EA] = xpm_to_mlx_img(tex->east);
		printf("tex->imgs[EA] img_ptr: %p\n", tex->imgs[EA].img_ptr);
		s_data()->feature_filled++;
		// printf(BOLD ORANGE "data->feature_filled: %u\n\n" RESET, s_data()->feature_filled);
	}
}
