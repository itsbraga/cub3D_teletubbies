/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:53:28 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 23:53:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

/*
	Draws the first (top) part of the triangle
	The function:
	- Calculates the y-range between points A and B
	- Updates x-coordinates using slope calculations
	- Draws horizontal lines to fill the upper part
*/
static void	__draw_first_part(t_mlx *mlx, t_triangle *tr, int color)
{
	int	start_y;
	int	end_y;

	start_y = (int)ceil(tr->a.y);
	end_y = (int)ceil(tr->b.y);
	if (start_y < end_y)
	{
		tr->curr_x1 += tr->slope1 * (start_y - tr->a.y);
		tr->curr_x2 += tr->slope2 * (start_y - tr->a.y);
		draw_hline_2d(mlx, tr, start_y, end_y, color);
	}
}

/*
	Draws the second (bottom) part of the triangle
	The function:
	- Calculates the y-range between points B and C
	- Updates x-coordinates using new slope calculations
	- Draws horizontal lines to fill the lower part
*/
static void	__draw_second_part(t_mlx *mlx, t_triangle *tr, int color)
{
	int	start_y;
	int	end_y;

	start_y = (int)ceil(tr->b.y);
	end_y = (int)ceil(tr->c.y);
	if (start_y < end_y)
	{
		tr->curr_x1 = tr->b.x + tr->slope3 * (start_y - tr->b.y);
		tr->curr_x2 = tr->a.x + tr->slope2 * (start_y - tr->a.y);
		tr->curr_slope1 = tr->slope3;
		tr->curr_slope2 = tr->slope2;
		draw_hline_2d(mlx, tr, start_y, end_y, color);
	}
}

void	fill_triangle_2d(t_mlx *mlx, t_point a, t_point b, t_point c,
int color)
{
	t_triangle	tr;

	init_triangle_2d(&tr, a, b, c);
	__draw_first_part(mlx, &tr, color);
	__draw_second_part(mlx, &tr, color);
}
