/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/13 19:08:31 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 * //TODO: set point und invers_points in einer function packen
 * //TODO: fill square
 * TODO: calculation has to be corrected
*/

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_lenght)
			 + (x * data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int mandel_loop(double x, double y)
{
	int cnt;
	double x_old;
	double y_old;
	double tmp;

	cnt = 0;
	x_old = x;
	y_old = y;
	while (cnt < 100 && (x_old*x_old) + (y_old*y_old) <= 4)
	{
		tmp = x_old;
		x_old = (x_old*x_old) - (y_old*y_old) + x;
		y_old = 2 * tmp * y_old + y;
		//z = sqrt((x_old*x_old) + (y_old*y_old));
/*		if(z > 2)
			break;*/
		cnt++;
	}
	return (cnt);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	start_fractols()
{
	t_vars	my_data;
	double	x;
	double	y;
	int		i;
	double	range;

	x = 0;
	y = 0;
	my_data.x_max = 2;
	my_data.x_min = -2;
	my_data.y_max = 2;
	my_data.y_min = -2;
	my_data.mlx = mlx_init();
	my_data.win = mlx_new_window(my_data.mlx, 600, 400, "Fractols");
	my_data.img = mlx_new_image(my_data.mlx, 400, 400);
	my_data.addr = mlx_get_data_addr(my_data.img, &my_data.bits_per_pixel,
			&my_data.line_lenght, &my_data.endian);
	//? Here comes the code to put the pixels
	range = ((my_data.x_max - my_data.x_min )/ 400);
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			i = mandel_loop(my_data.x_min+x*range , my_data.y_max-y*range);
			my_mlx_pixel_put(&my_data, x, y, create_trgb(0, 5, i * 5, i * 20));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(my_data.mlx, my_data.win, my_data.img, 0, 0);
	mlx_loop(my_data.mlx);

}