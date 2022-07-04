/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_get_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:27 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

t_color	bettermlx_get_color(t_image *image, int x, int y)
{
	unsigned char	*position;

	position = bettermlx_get_memory_position(image, x, y);
	if (position == NULL)
		return (create_color(0, 0, 0, 0));
	return (create_color(position[3], position[2], position[1], position[0]));
}
