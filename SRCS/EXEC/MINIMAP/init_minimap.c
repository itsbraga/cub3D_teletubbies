/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:59:14 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 21:06:14 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	Ajuster la taille de la minimap selon la taille de la window:

	WIN_SIZE (x,y) / (div TILE_SIZE) = MINIMAP_SIZE (x,y)
	WIN_SIZE (x,y) / MINIMAP_SIZE (x,y) = (div TILE_SIZE)
*/
int	init_minimap_img(t_mlx *mlx, t_minimap *minimap)
{
	minimap->img.img_ptr = mlx_new_image(mlx->mlx_ptr, 256, 256);
	if (minimap->img.img_ptr == NULL)
	{
		err_msg("minilibX", ERR_IMG);
		return (FAILURE);
	}
	minimap->img.addr = mlx_get_data_addr(minimap->img.img_ptr, 
			&minimap->img.bits_per_pixel,
			&minimap->img.size_line,
			&minimap->img.endian);
	if (minimap->img.addr == NULL)
	{
		del_img(mlx, minimap->img.img_ptr);
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_ADDR), FAILURE);
		 // check si ok pour minimap
		 // a verifier, peut-etre supprimer les deux images (minimap + mlx)
	}
	minimap->img.width = 256; // a changer
	minimap->img.height = 256; // a changer
	return (SUCCESS);
}
