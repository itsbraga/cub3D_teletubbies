/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:35:52 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/16 17:27:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	degree_to_radian(int degree)
{
	return (degree * (PI / 180));
}

float	square(float to_square)
{
	float result;

	result = to_square * to_square;
	return (result);
}

float	norm_rad_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > (2 * PI))
		angle -= (2 * PI);
	return (angle);
}

int	norm_h_angle(int angle)
{
	if (angle < 0)
		angle += 360;
	else if (angle > 360)
		angle = angle % 360;
	return (angle);
}

int	norm_v_angle(int angle)
{
	if (angle < -MAX_PITCH)
		angle = -MAX_PITCH;
	else if (angle > MAX_PITCH)
		angle = MAX_PITCH;
	return (angle);
}
