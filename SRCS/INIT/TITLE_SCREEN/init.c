/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:45:00 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/05 18:19:39 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_title_screen(t_title_screen *screen)
{
	background(screen);
	start_button(screen);
	// controls_menu(screen);
}

void	draw_title_screen(t_game *game, t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			game->title_screen.first_layer.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			game->title_screen.second_layer.img.img_ptr,
			game->title_screen.second_layer.pos.x,
			game->title_screen.second_layer.pos.y);
}
