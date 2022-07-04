/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_put_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:07:19 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

void	bettermlx_put_image(t_window *window, \
	t_image *image, \
	int x, \
	int y)
{
	int				current_x;
	int				current_y;

	current_y = -1;
	while (++current_y < image->height)
	{
		current_x = -1;
		while (++current_x < image->width)
			bettermlx_pixel_put(window,
				create_vector(x + current_x, y + current_y, 0),
				bettermlx_get_color(image, current_x, current_y),
				1);
	}
}
