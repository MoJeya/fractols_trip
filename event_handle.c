/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:41 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/22 18:16:47 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 * TODO: get mouse location x;y
*/

int	mouse_press_hook(int keycode, int x, int y, t_vars *frac)
{
	printf("Pointer: %p\n", &frac);
	if (keycode == 1)
	{
		frac->x_max -= 0.1;
		frac->x_min += 0.1;
		printf("max_iter: %f\n", frac->x_max);
	}
	if (keycode == 2)
	{
		start_fractols(frac);
	}
	return (0);
	(void)x;
	(void)y;
}
/**
 * 4 stands for buttonPress
 * 0 stands for allow every keypress
*/

void	set_hooks(t_vars *frac)
{
	printf("Pointer: %p\n", &frac);
	mlx_do_key_autorepeatoff(frac->mlx);
	mlx_hook(frac->win, 4, (1L<<2), mouse_press_hook, frac);
}
