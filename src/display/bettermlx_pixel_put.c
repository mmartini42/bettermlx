/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:39 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

void	bettermlx_pixel_put(
	t_window *window,
	t_vector3 pixel_coordinates,
	t_color color,
	float darkness)
{
	int		ay;
	int		my;
	int		ax;
	int		mx;

	ay = ((int)pixel_coordinates.vy) * window->divider;
	my = ay + window->divider;
	mx = ((int)pixel_coordinates.vx) * window->divider + window->divider;
	while (ay < my)
	{
		ax = ((int)pixel_coordinates.vx) * window->divider;
		while (ax < mx)
		{
			bettermlx_set_color(window->image, create_vector(ax, ay, 0),
				color, darkness);
			ax++;
		}
		ay++;
	}
}
