/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_set_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:49 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"
//t_image == image principale

void	bettermlx_set_color(t_image *image, t_vector3 pixel_coordinates,
	t_color color, float darkness)
{
	unsigned char	*position;

	if (color.a == 255)
		return ;
	position = bettermlx_get_memory_position(image, pixel_coordinates.vx,
			pixel_coordinates.vy);
	if (position == NULL)
		return ;
	if (darkness < 0)
		darkness = 0;
	position[0] = color.b * darkness;
	position[1] = color.g * darkness;
	position[2] = color.r * darkness;
	position[3] = color.a;
}
