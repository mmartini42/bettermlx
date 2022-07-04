/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_xpm_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:43 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

t_image	*bettermlx_init_xpm_image(t_window *window, char *path)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (image == NULL)
		return (NULL);
	image->width = 0;
	image->height = 0;
	image->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr, \
	path, \
	&image->width, \
	&image->height);
	if (image->img_ptr == NULL)
	{
		free(image);
		return (NULL);
	}
	image->img_addr = mlx_get_data_addr(image->img_ptr, \
	&image->bits_per_pixel, \
	&image->size_line, \
	&image->endian);
	return (image);
}
