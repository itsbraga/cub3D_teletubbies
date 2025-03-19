/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:41:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/12 18:11:47 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Draws the first (top) part of the triangle
	The function:
	- Calculates the y-range between points A and B
	- Updates x-coordinates using slope calculations
	- Draws horizontal lines to fill the upper part
*/
static void	__draw_first_part(t_minimap *mmap, t_triangle *tr, int color)
{
	int	start_y;
	int	end_y;

	start_y = (int)ceil(tr->a.y);
	end_y = (int)ceil(tr->b.y);
	if (start_y < end_y)
	{
		tr->curx1 += tr->slope1 * (start_y - tr->a.y);
		tr->curx2 += tr->slope2 * (start_y - tr->a.y);
		draw_hline(mmap, tr, start_y, end_y, color);
	}
}

/*
	Draws the second (bottom) part of the triangle
	The function:
	- Calculates the y-range between points B and C
	- Updates x-coordinates using new slope calculations
	- Draws horizontal lines to fill the lower part
*/
static void	__draw_second_part(t_minimap *mmap, t_triangle *tr, int color)
{
	int	start_y;
	int	end_y;

	start_y = (int)ceil(tr->b.y);
	end_y = (int)ceil(tr->c.y);
	if (start_y < end_y)
	{
		tr->curx1 = tr->b.x + tr->slope3 * (start_y - tr->b.y);
		tr->curx2 = tr->a.x + tr->slope2 * (start_y - tr->a.y);
		tr->cur_slope1 = tr->slope3;
		tr->cur_slope2 = tr->slope2;
		draw_hline(mmap, tr, start_y, end_y, color);
	}
}

static void	__fill_triangle(t_minimap *mmap, t_point a, t_point b, t_point c,
int color)
{
	t_triangle	tr;

	init_triangle(&tr, a, b, c);
	__draw_first_part(mmap, &tr, color);
	__draw_second_part(mmap, &tr, color);
}

/*
	Draws the player as a directional triangle on the minimap
	The function:
	- Calculates triangle dimensions based on tile size
	- Computes triangle points using player's position and direction
	- Creates an isosceles triangle pointing in player's direction
	- Draws both outline and filled triangle in red
	Note: Triangle size is slightly smaller than tile size (tile_size - 5)
*/
void	draw_player(t_minimap *mmap, t_player *player)
{
	int			L;
	double		h;
	float		offset_dist;
	t_triangle	iso;
	t_point		new_pos;

	L = mmap->tile_size - 5;
	h = 1.3 * L;
	offset_dist = L / 2;
	ft_memset(&iso, 0, sizeof(t_triangle));
	iso.theta = degree_to_radian(player->dir);
	new_pos.x = player->pos.x - cos(iso.theta) * offset_dist;
	new_pos.y = player->pos.y - sin(iso.theta) * offset_dist;
	iso.a.x = new_pos.x + cos(iso.theta) * h;
	iso.a.y = new_pos.y + sin(iso.theta) * h;
	iso.b.x = new_pos.x + cos(iso.theta + (PI / 2)) * offset_dist;
	iso.b.y = new_pos.y + sin(iso.theta + (PI / 2)) * offset_dist;
	iso.c.x = new_pos.x + cos(iso.theta - (PI / 2)) * offset_dist;
	iso.c.y = new_pos.y + sin(iso.theta - (PI / 2)) * offset_dist;
	draw_line(&mmap->img, iso.a, iso.b, RED_PIX);
	draw_line(&mmap->img, iso.b, iso.c, RED_PIX);
	draw_line(&mmap->img, iso.c, iso.a, RED_PIX);
	__fill_triangle(mmap, iso.a, iso.b, iso.c, RED_PIX);
}
