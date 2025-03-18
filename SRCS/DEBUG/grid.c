/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:15:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/18 00:33:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__draw_vgrid(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = TILE_SIZE;
	p1.y = 0;
	p2.x = TILE_SIZE;
	p2.y = WIN_HEIGHT;
	while (p1.x < WIN_WIDTH)
	{
		draw_line(&mlx->img, p1, p2, BLACK_PIX);
		p1.x += TILE_SIZE;
		p2.x += TILE_SIZE;
	}
	return ;
}

static void	__draw_hgrid(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.x = 0;
	p1.y = TILE_SIZE;
	p2.x = WIN_WIDTH;
	p2.y = TILE_SIZE; 
	while (p1.y < WIN_HEIGHT)
	{
		draw_line(&mlx->img, p1, p2, BLACK_PIX);
		p1.y += TILE_SIZE;
		p2.y += TILE_SIZE;
	}
	return ;
}

void	draw_grid(t_mlx *mlx)
{
	__draw_hgrid(mlx);
	__draw_vgrid(mlx);
}
