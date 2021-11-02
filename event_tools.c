/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:12:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/02 14:29:17 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

void	ft_diff_point(t_vars *frac, int keycode)
{
	if (frac->mod == 2)
	{
		if (keycode == KEY_DOWN && frac->p_cnt <= 3 && frac->p_cnt > 0)
		{
			frac->p_cnt--;
			frac->c = frac->p[frac->p_cnt];
			start_fractols(frac);
		}
		if (keycode == KEY_UP && frac->p_cnt >= 0 && frac->p_cnt < 2)
		{
			frac->p_cnt++;
			frac->c = frac->p[frac->p_cnt];
			start_fractols(frac);
		}
	}
}

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

void	ft_movement(int keycode, t_vars *frac)
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
}
