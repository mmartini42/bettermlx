/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_clean_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:11 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

void	bettermlx_clean_display(t_window *window)
{
	t_color	clean_color;
	int		x;
	int		y;

	clean_color = create_color((char)0, (char)0, (char)0, (char)0);
	x = 0;
	while (x < window->image->width)
	{
		y = 0;
		while (y < window->image->height)
		{
			bettermlx_pixel_put(window, create_vector(x, y, 0), clean_color, 1);
			y++;
		}
		x++;
	}
}
