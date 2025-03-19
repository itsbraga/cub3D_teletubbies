/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:38:24 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/19 03:27:45 by art3mis          ###   ########.fr       */
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

void	init_minimap(t_minimap *mmap, t_game *game)
{
	ft_bzero(mmap, sizeof(t_minimap));
	ft_bzero(&mmap->vp, sizeof(t_viewport));
	ft_bzero(&mmap->img, sizeof(t_img));
	ft_bzero(&mmap->pos, sizeof(t_point));
	mmap->ratio = 0.15; // 15% de la window
	if (__init_minimap_img(game->mlx, mmap) == FAILURE)
		return (err_msg("minilibX", ERR_INIT_MMAP_IMG));
	game->mmap = mmap;
}
