/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:09:28 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 19:16:29 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	render_frame(t_game *game)
{
	if (game->state == TITLE_SCREEN)
		draw_title_screen(game, game->mlx);
	else if (game->state == GAME)
	{
		move_player(game, game->keys);
		reset_move(game->player);
		clear_img(&game->mlx->img, WIN_WIDTH, WIN_HEIGHT, GRAY_PIX);
		raycasting(game->data, game->player, game->ray);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->mlx->img.img_ptr, 0, 0);
		#if BONUS
			render_minimap(game, game->mmap);
			// render_weapon(game, game->data->weapon);
		#endif
	}
	return (SUCCESS);
}
