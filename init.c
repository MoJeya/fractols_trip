/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:29:13 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/28 17:37:33 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

void init_data(t_vars *fractol)
{
	fractol->x_max = 2;
	fractol->x_min = -2;
	fractol->y_min = -2;
	fractol->y_max = 2;
	fractol->window_width_x = 400;
	fractol->window_height_y = 400;
	fractol->m_pos.x = 0;
	fractol->m_pos.y = 0;
	fractol->max_iter = 200;
	fractol->max_calc = 4;
	fractol->color_shift = 0;
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, 600, 400, "Fractols");
	fractol->img = mlx_new_image(fractol->mlx, 400, 400);
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->line_lenght, &fractol->endian);
}

t_point init_pos(int x, int y)
{
	t_point pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
