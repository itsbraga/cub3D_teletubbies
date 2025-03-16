/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/16 20:31:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__init_minimap_img(t_mlx *mlx, t_minimap *minimap)
{
	int	m_width;
	int	m_height;

	m_width = minimap->vp.pixel_width;
	m_height = minimap->vp.pixel_height;
	minimap->img.img_ptr = mlx_new_image(mlx->mlx_ptr, m_width, m_height);
	if (minimap->img.img_ptr == NULL)
		return (err_msg("minilibX", ERR_IMG), FAILURE);
	minimap->img.addr = mlx_get_data_addr(minimap->img.img_ptr, 
		&minimap->img.bits_per_pixel,
		&minimap->img.size_line,
		&minimap->img.endian);
	if (minimap->img.addr == NULL)
	{
		del_img(mlx, minimap->img.img_ptr);
		free_mlx(mlx); // peut-etre supprimer les deux images (minimap + mlx)
		return (err_msg("minilibX", ERR_ADDR), FAILURE);
	}
	minimap->img.width = m_width;
	minimap->img.height = m_height;
	minimap->pos.x = WIN_WIDTH - m_width - 20;
	minimap->pos.y = WIN_HEIGHT - m_height - 20;
	return (SUCCESS);
}

void	render_minimap(t_game *game, t_minimap *minimap)
{
	minimap->vp = compute_viewport(game, minimap);
	if (__init_minimap_img(game->mlx, minimap) == FAILURE)
		return (err_msg("minilibX", ERR_INIT_MMAP_IMG));
	clear_img(&minimap->img, minimap->img.width, minimap->img.height,
		RUSS_PURPLE_PIX);
	draw_viewport_walls(minimap, s_data()->map);
	draw_player_in_viewport(game, minimap);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		minimap->img.img_ptr, minimap->pos.x, minimap->pos.y);
}
