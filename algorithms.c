/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:27:53 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/02 15:35:00 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

int	burningship_loop(double x, double y, t_vars *fractol)
{
	int		cnt;
	double	a;
	double	b;
	double	two_ab;

	cnt = 0;
	a = x;
	b = y;
	while (cnt < fractol->max_iter)
	{
		two_ab = 2 * a * b;
		a = (a * a) - (b * b) + x;
		b = fabs(two_ab) + y;
		if ((a * a) + (b * b) >= fractol->max_calc)
			break ;
		cnt++;
	}
	return (cnt);
}

int	mandel_loop(double x, double y, t_vars *fractol)
{
	int		cnt;
	double	a;
	double	b;
	double	two_ab;

	cnt = 0;
	a = x;
	b = y;
	while (cnt < fractol->max_iter)
	{
		two_ab = 2 * a * b;
		a = (a * a) - (b * b) + x;
		b = two_ab + y;
		if ((a * a) + (b * b) >= 4)
			break ;
		cnt++;
	}
	return (cnt);
}

int	julia_loop(double x, double y, t_vars *fractol)
{
	int		cnt;
	double	a;
	double	b;
	double	two_ab;

	cnt = 0;
	a = x;
	b = y;
	while (cnt < fractol->max_iter)
	{
		two_ab = 2 * a * b;
		a = (a * a) - (b * b) + fractol->c.x;
		b = two_ab + fractol->c.y;
		if ((a * a) + (b * b) >= 4)
			break ;
		cnt++;
	}
	return (cnt);
}
