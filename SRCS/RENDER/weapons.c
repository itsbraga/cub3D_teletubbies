/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:58:18 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/19 03:28:15 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_weapon(t_weapon *w, t_data *data)
{
	w->id = -1;
	w->xpm_nb = 4;
	w->sprites = yama(CREATE, NULL, sizeof(t_img) * (w->xpm_nb));
	w->state = IDLE;
	w->frame_counter = 0;
	ft_bzero(&w->pos, sizeof(t_point));
	data->weapon = w;
}

void	get_weapons(t_weapon *w)
{
	w->id = 1;
	w->sprites[0] = xpm_to_mlx_img("./SPRITES/SPRITES_ARMORY/MP40/MP40_idle.xpm");
	w->sprites[1] = xpm_to_mlx_img("./SPRITES/SPRITES_ARMORY/MP40/MP40_recoil1.xpm");
	w->sprites[2] = xpm_to_mlx_img("./SPRITES/SPRITES_ARMORY/MP40/MP40_fire.xpm");
	w->sprites[3] = xpm_to_mlx_img("./SPRITES/SPRITES_ARMORY/MP40/MP40_recoil2.xpm");
	w->pos.x = WIN_WIDTH / 2;
	w->pos.y = WIN_HEIGHT / 2;
}

void	draw_weapon(t_game *game, t_weapon *w)
{
	t_mlx *mlx;
	
	mlx = game->mlx;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, w->sprites[0].img_ptr, 
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

void	render_weapon(t_game *game, t_weapon *w)
{
	get_weapons(w);
	draw_weapon(game, w);
}