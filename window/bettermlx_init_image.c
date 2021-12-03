/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:32 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/25 20:42:33 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

t_image	*bettermlx_init_image(t_window *window, int width, int height)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->width = width;
	image->height = height;
	image->img_ptr = mlx_new_image(window->mlx_ptr, \
	width, \
	height);
	image->img_addr = mlx_get_data_addr(image->img_ptr, \
	&image->bits_per_pixel, \
	&image->size_line, \
	&image->endian);
	return (image);
}
