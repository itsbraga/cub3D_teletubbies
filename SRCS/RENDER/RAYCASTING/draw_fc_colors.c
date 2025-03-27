/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:31:34 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/27 16:31:41 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_floor_color(t_raycasting *r, t_data *d)
{
	int		curr_x;
	int		curr_y;
	int		color;
	float	shadow_factor;
	t_img	*img;

	curr_x = r->curr_ray;
	curr_y = r->wall_end_y;
	img = &s_mlx()->img;
	while (curr_y <= WIN_HEIGHT)
	{
		shadow_factor = ((float)curr_y / (float)WIN_HEIGHT) - 0.25;
		if (shadow_factor < 0.1f)
			shadow_factor = 0.1f;
		// printf("shadow factor = %f\n", shadow_factor);
		color = apply_shadow_factor((int)d->floor_color, shadow_factor);
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ;
}

void	draw_ceiling_color(t_raycasting *r, t_data *d)
{
	int		curr_x;
	int		curr_y;
	int		color;
	float	shadow_factor;
	t_img	*img;

	curr_x = r->curr_ray;
	curr_y = 0;
	img = &s_mlx()->img;
	while (curr_y <= r->wall_start_y)
	{
		shadow_factor = 1.0f - ((float)curr_y / (float)(WIN_HEIGHT / 2));
		if (shadow_factor < 0.1f)
			shadow_factor = 0.1f;
		// printf("%s | shadow factor = %f\n", __func__, shadow_factor);
		color = apply_shadow_factor((int)d->ceiling_color, shadow_factor);
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ;
}
