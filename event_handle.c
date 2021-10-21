/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:41 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/21 13:05:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 * TODO: get mouse location x;y
*/

//void	ft_zoom(int x, int y, t_fractol *frac)
//{
//	frac->pos->x = ((x / 1.20 + frac->pos->x) - (x / 1.20));
//	frac->pos->y = ((y / 1.20) + (frac->pos->y) - (y / 1.20));
//	frac->max.x--;
//	frac->max.y--;
//	frac->min.x++;
//	frac->min.y++;
//}

//void	ft_dezoom(int x, int y, t_fractol *frac)
//{
//	frac->pos->x = ((x / 0.80 + frac->pos->x) - (x / 0.80));
//	frac->pos->y = ((y / 0.80) + (frac->pos->y) - (y / 0.80));
//	frac->max.x++;
//	frac->max.y++;
//	frac->min.x--;
//	frac->min.y--;
//}

int	mouse_press_hook(int keycode, int x, int y, t_fractol *frac)
{
	printf("pointer: %p\n", &frac);
	if (keycode == 5)
	{
		//funtion for mouse position
		//ft_zoom(frac);
		printf("mouse pos(%d ; %d)\n", x, y);
		frac->max_iteration = 80;
	}
	if (keycode == 1)
	{
		printf("MAX_ITERATION: %d\n", frac->max_iteration);
	}
	return (0);
}
/**
 * 4 stands for buttonPress
 * 0 stands for allow every keypress
*/

void	set_hooks(t_fractol *frac)
{
	printf("pointer: %p\n", frac);
	mlx_do_key_autorepeatoff(frac->my_data->mlx);
	mlx_hook(frac->my_data->win, 4, 0, mouse_press_hook, frac);
	printf("max_iteration:%d\n", frac->max_iteration);
}
