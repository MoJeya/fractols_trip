/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:29:13 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/20 17:26:39 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

t_vars	init_data(void)
{
	t_vars	my_data;

	my_data.x_max = 2;
	my_data.x_min = -2;
	my_data.y_max = 2;
	my_data.y_min = -2;
	my_data.mlx = mlx_init();
	my_data.win = mlx_new_window(my_data.mlx, 600, 400, "Fractols");
	my_data.img = mlx_new_image(my_data.mlx, 400, 400);
	my_data.addr = mlx_get_data_addr(my_data.img, &my_data.bits_per_pixel,
			&my_data.line_lenght, &my_data.endian);
	return (my_data);
}

t_point init_pos(int x, int y)
{
	t_point pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_fractol	init_fractol(t_vars *my_data, t_point pos)
{
	t_fractol	fractol;

	fractol.my_data = my_data;
	fractol.max_iteration = 200;
	fractol.max.x = my_data->x_max;
	fractol.max.y = my_data->y_max;
	fractol.min.x = my_data->x_min;
	fractol.min.y = my_data->y_min;
	fractol.pos = pos;
	return (fractol);
}
