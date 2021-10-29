/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:41 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/29 16:48:43 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 *TODO:
 * 3) rebuild colorshift
 * //1) implement move functionality
 * //2) build iteration change on button press
 * 4) claen up
 * 5) multithreading
*/

void	ft_zoom(t_vars *frac, int x, int y)
{
	frac->m_pos.x = (double)x / (frac->window_width_x
			/ (frac->x_max - frac->x_min)) + frac->x_min;
	frac->m_pos.y = (double)y / (frac->window_height_y
			/ (frac->y_max - frac->y_min)) * -1 + frac->y_max;
	frac->x_max = inter_pol(frac->m_pos.x, frac->x_max, (1 / 1.10));
	frac->y_max = inter_pol(frac->m_pos.y, frac->y_max, (1 / 1.10));
	frac->x_min = inter_pol(frac->m_pos.x, frac->x_min, (1 / 1.10));
	frac->y_min = inter_pol(frac->m_pos.y, frac->y_min, (1 / 1.10));
	start_fractols(frac);
}

void	ft_dezoom(t_vars *frac, int x, int y)
{
	frac->m_pos.x = (double)x / (frac->window_width_x
			/ (frac->x_max - frac->x_min)) + frac->x_min;
	frac->m_pos.y = (double)y / (frac->window_height_y
			/ (frac->y_max - frac->y_min)) * -1 + frac->y_max;
	frac->x_max = inter_pol(frac->m_pos.x, frac->x_max, (1 / 0.80));
	frac->y_max = inter_pol(frac->m_pos.y, frac->y_max, (1 / 0.80));
	frac->x_min = inter_pol(frac->m_pos.x, frac->x_min, (1 / 0.80));
	frac->y_min = inter_pol(frac->m_pos.y, frac->y_min, (1 / 0.80));
	start_fractols(frac);
}

int	key_handel(int keycode, t_vars *frac)
{
	if (keycode == KEY_W)
	{
		frac->y_max -= 0.05;
		frac->y_min -= 0.05;
		start_fractols(frac);
	}
	if (keycode == KEY_S)
	{
		frac->y_max += 0.05;
		frac->y_min += 0.05;
		start_fractols(frac);
	}
	if (keycode == KEY_D)
	{
		frac->x_max -= 0.05;
		frac->x_min -= 0.05;
		start_fractols(frac);
	}
	if (keycode == KEY_A)
	{
		frac->x_max += 0.05;
		frac->x_min += 0.05;
		start_fractols(frac);
	}
	if (keycode == KEY_PLUS)
	{
		frac->max_calc += 20;
		start_fractols(frac);
	}
	if (keycode == KEY_MINUS)
	{
		frac->max_calc -= 1;
		start_fractols(frac);
	}
	if (keycode == COLOR_KEY)
	{
		frac->max_iter += 100;
		start_fractols(frac);
	}
	return (0);
}

int	mouse_press_hook(int keycode, int x, int y, t_vars *frac)
{
	if (keycode == M_SCROLL_UP)
	{
		ft_zoom(frac, x, y);
	}
	if (keycode == M_SCROLL_DOWN)
	{
		ft_dezoom(frac, x, y);
	}
	return (0);
}

void	set_hooks(t_vars *frac)
{
	mlx_do_key_autorepeatoff(frac->mlx);
	mlx_key_hook(frac->win, key_handel, frac);
	mlx_hook(frac->win, 4, (1L<<2), mouse_press_hook, frac);
}
