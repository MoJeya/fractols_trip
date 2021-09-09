/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/09 19:33:08 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int key_hook(int keycode, t_vars *my_struct)
{
	if(keycode == 2)
	{
		printf("Hello from key_hook!\n");
		mlx_loop(my_struct->mlx);
	}
	return (0);
}

void start_fractols()
{
	t_data	data;
	t_vars	my_struct;

	my_struct.mlx = mlx_init();
	my_struct.win = mlx_new_window(my_struct.mlx, 1920, 1080, "Fractols_42");
	data.img = mlx_new_image(my_struct.mlx, 1300, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_lenght, &data.endian);
	my_mlx_pixel_put(&data, 100, 100, 0x00FF0000);
	mlx_key_hook(my_struct.win, key_hook, &my_struct);
	mlx_loop(my_struct.mlx);
}
