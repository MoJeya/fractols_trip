/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/02 15:53:32 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

double	inter_pol(double start, double end, double inter)
{
	return (start + (end - start) * inter);
}

void	put_color(t_vars *fr, int x, int y)
{
	my_mlx_pixel_put(fr, x, y,
		create_trgb(0, 5, fr->color_shift * 5, fr->color_shift * 20));
}

void	load_img(t_vars *fr)
{
	mlx_put_image_to_window(fr->mlx,
		fr->win, fr->img, 0, 0);
}

static void	pick_loop(t_vars *fr)
{
	if (fr->mod == 1)
		fr->color_shift = mandel_loop(fr->img_val.x, fr->img_val.y, fr);
	if (fr->mod == 2)
		fr->color_shift = julia_loop(fr->img_val.x, fr->img_val.y, fr);
	if (fr->mod == 3)
		fr->color_shift = burningship_loop(fr->img_val.x, fr->img_val.y, fr);
}

int	start_fractols(t_vars *fr)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	fr->range.x = ((fr->x_max - fr->x_min) / fr->window_width_x);
	fr->range.y = ((fr->y_max - fr->y_min) / fr->window_height_y);
	while (y < fr->window_height_y)
	{
		x = 0;
		while (x < fr->window_width_x)
		{
			fr->img_val.x = fr->x_min + x * fr->range.x;
			fr->img_val.y = fr->y_max - y * fr->range.y;
			pick_loop(fr);
			put_color(fr, x, y);
			x++;
		}
		y++;
	}
	load_img(fr);
	return (0);
}
