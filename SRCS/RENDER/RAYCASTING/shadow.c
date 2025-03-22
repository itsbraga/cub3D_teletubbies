/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:32:39 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 22:50:28 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	calculate_shadow_factor(float distance)
{
	float	shadow_factor;
	
	shadow_factor = 1.0f - (distance / VISIBILITY_DIST_MAX);
	if (shadow_factor < 0.1f)
		shadow_factor = 0.1f;
	return (shadow_factor);
}

int	apply_shadow_factor(int color, float shadow_factor)
{
	int color_shadowed;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * shadow_factor);
	g = (int)(g * shadow_factor);
	b = (int)(b * shadow_factor);
	color_shadowed = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
	return (color_shadowed);
}
