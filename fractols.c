/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/14 19:18:07 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

/**
 * TODO: set point und invers_points in einer function packen
*/

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + ((y * data->line_lenght) + (x * data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int	set_point(t_vars *data,int *x, int *y, int flag, int len)
{
	int cnt;

	cnt = 0;
	while (cnt < len)
	{
		if (flag == 0)
			(*x)++;
		else if (flag == 1)
			(*y)++;
		my_mlx_pixel_put(data, (*x), (*y), 0x00FF0000);
		cnt++;
	}
	return (0);
}


void invers_points(t_vars *data,int *x, int *y, int flag, int len)
{
	int cnt;

	cnt = 0;
	while (cnt > len)
	{
		if (flag == 0)
			(*x)--;
		else if (flag == 1)
			(*y)--;
		my_mlx_pixel_put(data, (*x), (*y), 0x00FF0000);
		cnt--;
	}
}

/**
 * x und y werden als punkte Uebergeben
 * und wareaend ein neuer punkt gezeichnet wird werd auch Automatisch eine
 * neue Koordinate abgespeichert, durch die addressen von den variabeln x und y
*/

void start_fractols()
{
	t_vars my_data;
	int x, y, cnt;

	x = 1920/2;
	y = 1080/2;
	cnt = 0;
	my_data.mlx = mlx_init();
	my_data.win = mlx_new_window(my_data.mlx, 1920, 1080, "Fractols");
	my_data.img = mlx_new_image(my_data.mlx, 1920, 1080);
	my_data.addr = mlx_get_data_addr(my_data.img, &my_data.bits_per_pixel, &my_data.line_lenght, &my_data.endian);
	set_point(&my_data, &x, &y, 0, 100);
	set_point(&my_data, &x, &y, 1, 100);
	invers_points(&my_data, &x, &y, 0, -100);
	invers_points(&my_data, &x, &y, 1, -100);
	//my_mlx_pixel_put(&my_data, x, y, 0x00FF0000);
	//my_mlx_pixel_put(&my_data, x, y, 0x00FF0000);
	mlx_put_image_to_window(my_data.mlx, my_data.win, my_data.img, 0, 0);
	mlx_loop(my_data.mlx);
}
