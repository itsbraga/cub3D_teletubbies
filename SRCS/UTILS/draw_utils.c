/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:22:58 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 04:03:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	swap_point(t_point *p0, t_point *p1)
{
	t_point tmp;

	tmp = *p0;
	*p0 = *p1;
	*p1 = tmp;
}

bool	is_valid_point(t_point point, size_t win_width, size_t win_height)
{
	if (point.x > win_width || point.x < 0)
		return (false);
	if (point.y > win_height || point.y < 0)
		return (false);
	return (true);
}
