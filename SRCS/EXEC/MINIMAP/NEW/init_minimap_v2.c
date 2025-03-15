/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:14 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/15 20:15:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_minimap_img_v2(t_mlx *mlx, t_minimap *minimap)
{
	int	m_width;
	int	m_height;

	m_width = minimap->vp.pixel_width;
	m_height = minimap->vp.pixel_height;
	minimap->img.img_ptr = mlx_new_image(mlx->mlx_ptr, 256, 256);
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
