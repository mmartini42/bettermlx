/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:41:58 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

void	bettermlx_hook(
	t_window *window,
	t_x11event x11event,
	int (*funct)(),
	void *param)
{
	mlx_hook(window->win_ptr, x11event, 0, funct, param);
}
