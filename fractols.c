/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/28 19:16:04 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

double	inter_pol(double start, double end, double inter)
{
	return (start + (end - start) * inter);
}

static int	mandel_loop(double x, double y, t_vars *fractol)
{
	int		cnt;
	double	x_old;
	double	y_old;
	double	tmp;

	cnt = 0;
	x_old = x;
	y_old = y;
	while (cnt < fractol->max_iter && (x_old * x_old) + (y_old * y_old) <= fractol->max_calc)
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

void	put_color(t_vars *fractol, int x, int y)
{
	my_mlx_pixel_put(fractol, x, y,
		create_trgb(0, 5, fractol->color_shift * 5, fractol->color_shift * 20));
}

int	start_fractols(t_vars *fractol)
{
	//int			color_shift;
	int			x;
	int			y;
	double		range_x;

	x = 0;
	y = 0;
	range_x = ((fractol->x_max - fractol->x_min) / fractol->window_width_x);
	while (y < fractol->window_height_y)
	{
		x = 0;
		while (x < fractol->window_width_x)
		{
			fractol->color_shift = mandel_loop(fractol->x_min
					+ x * range_x,
					fractol->y_max - y * range_x, fractol);
			put_color(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx,
		fractol->win, fractol->img, 0, 0);
	return (0);
}
