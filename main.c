/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:28:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/22 17:58:43 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

int	main(void)
{
	t_vars		*fractol;
	t_point		pos;

	pos = init_pos(0, 0);
	fractol = (t_vars *)malloc(sizeof(t_vars));
	init_data(fractol);
	start_fractols(fractol);
	set_hooks(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
