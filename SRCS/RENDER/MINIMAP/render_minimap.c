/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/17 23:23:20 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__check_mmap_tile_size(t_minimap *mmap)
{
	if (mmap->width < 128)
		mmap->width = 128;
	if (mmap->height < 128)
		mmap->height = 128;
}

static int	__init_minimap_img(t_mlx *mlx, t_minimap *mmap)
{
	mmap->width = (int)(WIN_WIDTH * mmap->ratio);
	mmap->height = (int)(WIN_HEIGHT * mmap->ratio);
	__check_mmap_tile_size(mmap);
	mmap->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mmap->width, mmap->height);
	if (mmap->img.img_ptr == NULL)
		return (err_msg("minilibX", ERR_IMG), FAILURE);
	mmap->img.addr = mlx_get_data_addr(mmap->img.img_ptr, 
		&mmap->img.bits_per_pixel,
		&mmap->img.size_line,
		&mmap->img.endian);
	if (mmap->img.addr == NULL)
	{
		del_img(mlx, mmap->img.img_ptr);
		free_mlx(mlx); // peut-etre supprimer les deux images (mmap + mlx)
		return (err_msg("minilibX", ERR_ADDR), FAILURE);
	}
	mmap->img.width = mmap->width;
	mmap->img.height = mmap->height;
	mmap->pos.x = WIN_WIDTH - mmap->width - 20;
	mmap->pos.y = WIN_HEIGHT - mmap->height - 20;
	return (SUCCESS);
}

void	render_minimap(t_game *game, t_minimap *mmap)
{
	if (__init_minimap_img(game->mlx, mmap) == FAILURE)
		return (err_msg("minilibX", ERR_INIT_MMAP_IMG));
	clear_img(&mmap->img, mmap->img.width, mmap->img.height, LGRAY_PIX);
	draw_minimap(mmap, s_data()->map); // changer en game->data
	draw_player_in_viewport(game, mmap);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		mmap->img.img_ptr, mmap->pos.x, mmap->pos.y);
}
