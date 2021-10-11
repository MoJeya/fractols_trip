/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/11 19:01:41 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 * //TODO: set point und invers_points in einer function packen
 * TODO: fill square
*/

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_lenght)
			 + (x * data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int	z_loop(double x, double y)
{
	int		cnt;

	x = (x*x) - (y*y) + x;
	y = 2 * x * y + y;
	cnt = 0;
	while (cnt < 100)
	{
		x = (x*x) - (y*y) + x;
		y = 2 * x * y + y;
		if (abs((int)x + (int)y)>=2)
			break;
		cnt++;
	}
	if (cnt == 100)
		return (1);
	else
		return (0);
}

void	fill_pane_w_pixle(double x, double y, t_vars *data)
{
	double	max_x;
	double	max_y;
	double	x_p = -2;
	double	y_p = -2;

	max_x = 1920;
	max_y = 1080;
	while (y < max_y)
	{
		if (x >= max_x)
		{
			x = 0;
			x_p = -2;
		}
		while (x < max_x)
		{
			if (z_loop(x_p, y_p) == 1)
				my_mlx_pixel_put(data, x, y, 0x00FF0000);
			x_p += 0.1;
			x++;
		}
		y_p += 0.1;
		y++;
	}
}

void	start_fractols()
{
	t_vars	my_data;
	int	x;
	int	y;

	x = 0;
	y = 0;
	my_data.mlx = mlx_init();
	my_data.win = mlx_new_window(my_data.mlx, 1920, 1080, "Fractols");
	my_data.img = mlx_new_image(my_data.mlx, 1920, 1080);
	my_data.addr = mlx_get_data_addr(my_data.img, &my_data.bits_per_pixel,
			&my_data.line_lenght, &my_data.endian);
	//? Here comes the code to put the pixels
	fill_pane_w_pixle(x, y, &my_data);
	mlx_put_image_to_window(my_data.mlx, my_data.win, my_data.img, 0, 0);
	mlx_loop(my_data.mlx);
}
