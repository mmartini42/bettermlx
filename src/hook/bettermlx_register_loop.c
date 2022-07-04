/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_register_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:03 by mathmart          #+#    #+#             */
/*   Updated: 2022/06/25 19:45:47 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

void	bettermlx_register_loop(t_window *window,
	void *param, int (*funct_ptr)())
{
	mlx_loop_hook(window->mlx_ptr, funct_ptr, param);
	mlx_loop(window->mlx_ptr);
}
