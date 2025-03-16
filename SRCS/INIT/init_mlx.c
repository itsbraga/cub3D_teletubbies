/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:07:04 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/16 19:42:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__init_mlx_img(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (mlx->img.img_ptr == NULL)
	{
		err_msg("minilibX", ERR_IMG);
		return (FAILURE);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, 
			&mlx->img.size_line,
			&mlx->img.endian);
	if (mlx->img.addr == NULL)
	{
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_ADDR), FAILURE);
	}
	return (SUCCESS);
}

void	init_mlx(t_mlx *mlx, t_game *game)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		free_mlx(mlx); // ou clean
		return (err_msg("minilibX", ERR_MLX));
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, W_NAME);
	if (mlx->win_ptr == NULL)
	{
		free_mlx(mlx);
		return (err_msg("minilibX", ERR_WIN));
	}
	if (__init_mlx_img(mlx) == FAILURE)
		return (err_msg("minilibX", ERR_INIT_IMG));
	game->mlx = mlx;
}
