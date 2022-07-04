/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_get_memory_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:32 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

unsigned char	*bettermlx_get_memory_position(t_image *image, int x, int y)
{
	unsigned char	*position;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return (NULL);
	position = ((unsigned char *)image->img_addr) + y * image->size_line
		+ x * 4;
	return (position);
}
