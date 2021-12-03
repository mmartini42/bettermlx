/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:44 by mathmart          #+#    #+#             */
/*   Updated: 2021/11/27 18:39:49 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Solong.h"

void	bettermlx_render(t_window *window)
{
	mlx_put_image_to_window(window->mlx_ptr, \
	window->win_ptr, \
	window->image->img_ptr, \
	0, \
	0);
}
