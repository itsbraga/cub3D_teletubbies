/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:12:20 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/18 00:15:33 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__fill_triangle(t_mlx *mlx, t_point p1, t_point p2, t_point p3, int color)
{
    // Tri des points par Y croissant
    if (p1.y > p2.y) { t_point temp = p1; p1 = p2; p2 = temp; }
    if (p1.y > p3.y) { t_point temp = p1; p1 = p3; p3 = temp; }
    if (p2.y > p3.y) { t_point temp = p2; p2 = p3; p3 = temp; }

    // Calcul des deltas pour chaque segment
    double dx12 = p2.x - p1.x;
    double dy12 = p2.y - p1.y;
    double dx13 = p3.x - p1.x;
    double dy13 = p3.y - p1.y;
    double dx23 = p3.x - p2.x;
    double dy23 = p3.y - p2.y;

    // Calcul des pentes avec protection contre la division par zéro
    double slope1;
    double slope2;
    double slope3;

    if (dy12 != 0)
        slope1 = dx12 / dy12;
    else
        slope1 = 0;

    if (dy13 != 0)
        slope2 = dx13 / dy13;
    else
        slope2 = 0;

    if (dy23 != 0)
        slope3 = dx23 / dy23;
    else
        slope3 = 0;

    // Variables pour le scanning
    double curx1 = p1.x;
    double curx2 = p1.x;

    // Première partie du triangle (du sommet à la ligne médiane)
    int sy = (int)ceil(p1.y);
    int ey = (int)ceil(p2.y);
    
    if (sy < ey) {
        curx1 += slope1 * (sy - p1.y);
        curx2 += slope2 * (sy - p1.y);
        
        for (int y = sy; y < ey; y++) {
            int x1 = (int)round(curx1);
            int x2 = (int)round(curx2);
            
            if (x1 > x2) { int temp = x1; x1 = x2; x2 = temp; }
            for (int x = x1; x <= x2; x++) {
                my_pixel_put_to_img(&mlx->img, color, x, y);
            }
            
            curx1 += slope1;
            curx2 += slope2;
        }
    }

    // Deuxième partie du triangle (de la ligne médiane au bas)
    sy = (int)ceil(p2.y);
    ey = (int)ceil(p3.y);
    
    if (sy < ey) {
        curx1 = p2.x + slope3 * (sy - p2.y);
        curx2 = p1.x + slope2 * (sy - p1.y);
        
        for (int y = sy; y < ey; y++) {
            int x1 = (int)round(curx1);
            int x2 = (int)round(curx2);
            
            if (x1 > x2) { int temp = x1; x1 = x2; x2 = temp; }
            for (int x = x1; x <= x2; x++) {
                my_pixel_put_to_img(&mlx->img, color, x, y);
            }
            
            curx1 += slope3;
            curx2 += slope2;
        }
    }
}

void	draw_player2d(t_mlx *mlx, t_player *player)
{
	int			L;
	double		h;
	float		offset_dist;
	t_triangle	iso;
	t_point		new_pos;

	L = 10;
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
    draw_line(&mlx->img, iso.a, iso.b, RED_PIX);
	draw_line(&mlx->img, iso.b, iso.c, RED_PIX);
	draw_line(&mlx->img, iso.c, iso.a, RED_PIX);
	__fill_triangle(mlx, iso.a, iso.b, iso.c, RED_PIX);
}
