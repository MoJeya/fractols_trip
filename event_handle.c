/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:41 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/22 19:17:41 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 * TODO: get mouse location x;y
*/

void	set_mouse_pos(int x, int y, t_vars *frac)
{
	frac->m_pos.x = x;
	frac->m_pos.y = y;
}

/*
 * Re: Digital zoom calculations
 * Vertical and horizontal image size (in pixel) should by divided by zoom factor. For example,
 * 2560x1920 (4.9MP) image after 2х digital zoom makes 1280x960 (1.23MP). Total Number of pixel should by divided
 * by zoom factor square. For 2x zoom you should divide by 4, 3x zoom -divide by 9 etc.
*/

void	ft_zoom(t_vars *frac)
{
	frac->x_max -= 0.1;
	frac->y_max -= 0.1;
	frac->x_min += 0.1;
	frac->y_min += 0.1;
	if (frac->x_max == 0 || frac-> x_min == 0)
	{
		frac->x_max = 0.0;
		frac->y_max = 0.0;
		frac->x_min = 0.0;
		frac->y_min = 0.0;
	}
}

void	ft_dezoom(t_vars *frac)
{
	frac->x_max += 0.1;
	frac->y_max += 0.1;
	frac->x_min -= 0.1;
	frac->y_min -= 0.1;
	if (frac->x_max == 0 || frac-> x_min == 0)
	{
		frac->x_max = 0.0;
		frac->y_max = 0.0;
		frac->x_min = 0.0;
		frac->y_min = 0.0;
	}
}

int	mouse_press_hook(int keycode, int x, int y, t_vars *frac)
{
	printf("Pointer: %p\n", &frac);
	if (keycode == ML_CLICK)
	{
		set_mouse_pos(x, y, frac);
	}
	if (keycode == M_SCROLL_UP)
	{
		ft_zoom(frac);
		printf("mouse pos: (%f;%f)\n", frac->m_pos.x, frac->m_pos.y);
		start_fractols(frac);
	}
	if (keycode == M_SCROLL_DOWN)
	{
		ft_dezoom(frac);
		start_fractols(frac);
	}
	return (0);
}

void	set_hooks(t_vars *frac)
{
	printf("Pointer: %p\n", &frac);
	mlx_do_key_autorepeatoff(frac->mlx);
	mlx_hook(frac->win, 4, (1L<<2), mouse_press_hook, frac);
}
