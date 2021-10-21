/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/21 12:39:23 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

static int	mandel_loop(double x, double y)
{
	int		cnt;
	double	x_old;
	double	y_old;
	double	tmp;

	cnt = 0;
	x_old = x;
	y_old = y;
	while (cnt < 200 && (x_old * x_old) + (y_old * y_old) <= 4)
	{
		tmp = x_old;
		x_old = (x_old * x_old) - (y_old * y_old) + x;
		y_old = 2 * tmp * y_old + y;
		cnt++;
	}
	return (cnt);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_image(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->my_data->mlx,
		fractol->my_data->win, fractol->my_data->img, 0, 0);
	mlx_destroy_image(fractol->my_data->mlx, fractol->my_data->img);
}

int	start_fractols(t_fractol *fractol)
{
	int			color_shift;
	int			x;
	int			y;
	double		range;

	x = 0;
	y = 0;
	range = ((fractol->my_data->x_max - fractol->my_data->x_min) / 400);
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			color_shift = mandel_loop(fractol->my_data->x_min
					+ x * range,
					fractol->my_data->y_max - y * range);
			my_mlx_pixel_put(fractol->my_data, x, y,
				create_trgb(0, 5, color_shift * 5,
					color_shift * 20));
			x++;
		}
		y++;
	}
	put_image(fractol);
	return (0);
}
