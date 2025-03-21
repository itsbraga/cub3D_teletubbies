/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                   			:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:15:24 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/19 02:15:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Sorts the three points of a triangle by their Y coordinates
	The function:
	- Compares Y coordinates of points pairwise
	- Swaps points if they are in wrong order
	- Ensures final order: a.y <= b.y <= c.y
	- Used to prepare triangle for rasterization from top to bottom
*/
static void	__sort_points_by_y(t_triangle *tr)
{
	t_point	tmp;

	if (tr->a.y > tr->b.y)
	{
		tmp = tr->a;
		tr->a = tr->b;
		tr->b = tmp;
	}
	if (tr->a.y > tr->c.y)
	{
		tmp = tr->a;
		tr->a = tr->c;
		tr->c = tmp;
	}
	if (tr->b.y > tr->c.y)
	{
		tmp = tr->b;
		tr->b = tr->c;
		tr->c = tmp;
	}
}

/*
	Calculates slopes between triangle points for the scanline algorithm
	
	In rasterization*, slopes help us:
	- Find where each horizontal scanline intersects the triangle edges
	- Calculate the X coordinates for each Y level we're drawing
	- Efficiently fill the triangle one horizontal line at a time
	
	The slopes calculated are:
	- slope1: top to middle point (a to b)
	- slope2: top to bottom point (a to c)
	- slope3: middle to bottom point (b to c)
	Each slope = dx/dy (change in x divided by change in y)
*/
static void	__compute_slopes(t_triangle *tr)
{
	double	dx;
	double	dy;

	dx = tr->b.x - tr->a.x;
	dy = tr->b.y - tr->a.y;
	if (dy != 0)
		tr->slope1 = dx / dy;
	else
		tr->slope1 = 0;
	dx = tr->c.x - tr->a.x;
	dy = tr->c.y - tr->a.y;
	if (dy != 0)
		tr->slope2 = dx / dy;
	else
		tr->slope2 = 0;
	dx = tr->c.x - tr->b.x;
	dy = tr->c.y - tr->b.y;
	if (dy != 0)
		tr->slope3 = dx / dy;
	else
		tr->slope3 = 0;
}

/*
	Draws a horizontal line segment (scanline) as part of triangle rasterization
	
	This is the core of the scanline rasterization algorithm:
	- For each Y level, calculates where the line intersects triangle edges
	- Fills all pixels between these intersection points
	- Updates intersection points for next Y level using pre-calculated slopes
	This creates a filled triangle one horizontal line at a time
*/
void	draw_hline(t_minimap *mmap, t_triangle *tr, int start_y, int end_y,
int color)
{
	int	x1;
	int	x2;
	int	temp;

	while (start_y < end_y)
	{
		x1 = (int)round(tr->curr_x1);
		x2 = (int)round(tr->curr_x2);
		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		while (x1 <= x2)
		{
			my_pixel_put_to_img(&mmap->img, color, x1, start_y);
			x1++;
		}
		tr->curr_x1 += tr->curr_slope1;
		tr->curr_x2 += tr->curr_slope2;
		start_y++;
	}
}

void	init_triangle(t_triangle *tr, t_point a, t_point b, t_point c)
{
	tr->a = a;
	tr->b = b;
	tr->c = c;
	__sort_points_by_y(tr);
	__compute_slopes(tr);
	tr->curr_x1 = tr->a.x;
	tr->curr_x2 = tr->a.x;
	tr->curr_slope1 = tr->slope1;
	tr->curr_slope2 = tr->slope2;
}
/*
	(*) Rasterization: Process of converting vector shapes (like triangles)
	into pixels on the screen. Since our screen is made of pixels (a grid),
	we need to determine which pixels should be colored to represent our
	triangle.
*/