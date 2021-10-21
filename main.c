/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:28:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/21 12:35:05 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

int	main(void)
{
	t_vars		my_data;
	t_point		pos;
	t_fractol	*fractol;

	my_data = init_data();
	pos = init_pos(0, 0);
	fractol = malloc(sizeof(fractol));
	*fractol = init_fractol(&my_data, pos);
	start_fractols(fractol);
	set_hooks(fractol);
	mlx_loop(fractol->my_data->mlx);
	return (0);
}
