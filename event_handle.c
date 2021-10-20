/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:03:41 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/20 18:02:01 by mjeyavat         ###   ########.fr       */
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

int	mouse_press_hook(int keycode/*, int x, int y,*/)
{
	//if(keycode == 4)
	//	ft_zoom(x, y, frac);
	//else if (keycode == 5)
	//	ft_dezoom(x, y, frac);
	//start_fractols(frac);
	printf("scroll up %d!\n", keycode);
	return (0);
}
/**
 * 4 stands for buttonPress
 * 0 stands for allow every keypress
*/

void	set_hooks(t_fractol frac)
{
	mlx_do_key_autorepeatoff(frac.my_data->mlx);
	mlx_hook(frac.my_data->win, 4, 0, mouse_press_hook, frac.my_data);
	printf("%f\n",frac.pos.x);
}
