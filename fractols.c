/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/27 18:44:13 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

double	inter_pol(double start, double end, double inter)
{
	return (start + (end - start) * inter);
}

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

void	put_image(t_vars *fractol)
{
	mlx_put_image_to_window(fractol->mlx,
		fractol->win, fractol->img, 0, 0);
}

int	start_fractols(t_vars *fractol)
{
	int			color_shift;
	int			x;
	int			y;
	double		range_x;

	x = fractol->s_pos.x;
	y = fractol->s_pos.y;
	range_x = ((fractol->x_max - fractol->x_min) / fractol->window_width_x);
	while (y < 400)
	{
		x = 0;
		while (x < 400)
		{
			color_shift = mandel_loop(fractol->x_min
					+ x * range_x,
					fractol->y_max - y * range_x);
			my_mlx_pixel_put(fractol, x, y,
				create_trgb(0, 5, color_shift * 5,
					color_shift * 20));
			x++;
		}
		y++;
	}
	put_image(fractol);
	return (0);
}
