/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:41 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/30 15:50:37 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 *TODO:
 *
 * 4) difrent point on key press Julia set
 *	//1) clean up event heandle
 * //3) rebuild colorshift
 * //1) implement move functionality
 * //2) build iteration change on button press
 * 5) multithreading
*/

int	key_handel(int keycode, t_vars *frac)
{
	ft_movement(keycode, frac);
	ft_diff_point(frac, keycode);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
	{
		if (keycode == KEY_PLUS)
			frac->max_calc += 20;
		else
			frac->max_calc -= 1;
		start_fractols(frac);
	}
	if (keycode == COLOR_KEY)
	{
		frac->max_iter += 100;
		start_fractols(frac);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(frac->mlx, frac->img);
		mlx_destroy_window(frac->mlx, frac->win);
		exit(1);
	}
	return (0);
}

int	mouse_press_hook(int keycode, int x, int y, t_vars *frac)
{
	if (keycode == M_SCROLL_UP)
		ft_zoom(frac, x, y);
	if (keycode == M_SCROLL_DOWN)
		ft_dezoom(frac, x, y);
	return (0);
}

void	set_hooks(t_vars *frac)
{
	mlx_do_key_autorepeatoff(frac->mlx);
	mlx_key_hook(frac->win, key_handel, frac);
	mlx_hook(frac->win, 4, (1L << 2), mouse_press_hook, frac);
}
