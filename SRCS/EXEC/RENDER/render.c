/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/15 20:30:47 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_textures(t_data *data)
{
	data->textures->imgs[NO] = xpm_to_mlx_img("./MAPS/VALID/TEXTURES/LAB_2B.xpm");
	data->textures->imgs[SO] = xpm_to_mlx_img("./MAPS/VALID/TEXTURES/TECH_4E.xpm");
	data->textures->imgs[WE] = xpm_to_mlx_img("./MAPS/VALID/TEXTURES/PIPES_1A.xpm");
	data->textures->imgs[EA] = xpm_to_mlx_img("./MAPS/VALID/TEXTURES/CONSOLE_1B.xpm");
}

int	render(t_game *game)
{
	t_data	*data;

	data = data_s();
	if (game->state == TITLE_SCREEN)
		draw_title_screen(game, game->mlx);
	else if (game->state == GAME)
	{
		get_map_info(data->map);
		get_textures(data);
		clear_img(&game->mlx->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
		raycasting(data, game->player, game->ray);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->mlx->img.img_ptr, 0, 0);
		if (BONUS)
			render_minimap(game, game->minimap);
		// 	render_minimap_v2(game, game->minimap);
	}
	return (SUCCESS);
}
