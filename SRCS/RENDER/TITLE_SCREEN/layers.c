/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:15:26 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/17 23:12:38 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	background(t_title_screen *s)
{
	s->first_layer = xpm_to_mlx_img("./TITLE_SCREEN/XPM/background_v2.xpm");
	if (s->first_layer.img_ptr == NULL)
		return (err_msg("Title screen", ERR_BG_IMG));
}

void	start_button(t_title_screen *s)
{
	s->second_layer.img = xpm_to_mlx_img("./TITLE_SCREEN/XPM/start_button.xpm");
	if (s->second_layer.img.img_ptr == NULL)
	{
		del_img(s_mlx(), s->first_layer.img_ptr);
		return (err_msg("Title screen", ERR_BUTTON_IMG));
	}
	s->second_layer.pos.x = (WIN_WIDTH - s->second_layer.img.width) / 2;
	s->second_layer.pos.y = WIN_HEIGHT - s->second_layer.img.height - 40;
	s->second_layer.width = s->second_layer.img.width;
	s->second_layer.height = s->second_layer.img.height;
}

void	controls_menu(t_title_screen *s);
