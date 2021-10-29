/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:28:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/29 18:33:19 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

void	load_info_to(t_vars *fr, int argc)
{
	if (argc > 2)
	{
		fr->img = mlx_xpm_file_to_image(fr->mlx, "./image/man.xpm",
				&fr->window_width_x, &fr->window_height_y);
		load_img(fr);
	}
	else
	{
		fr->img = mlx_xpm_file_to_image(fr->mlx, "./image/man.xpm",
				&fr->window_width_x, &fr->window_height_y);
		load_img(fr);
	}
}

int	main(int argc, char *argv[])
{
	t_vars		*fractol;
	int			input;

	input = 0;
	fractol = (t_vars *)malloc(sizeof(t_vars));
	init_data(fractol);
	if (argc == 2)
	{
		ft_putstr_fd("The argument supplied is 2", 1);
		input = ft_atoi(argv[1]);
		if (input == 1)
			fractol->mod = input;
		if (input == 2)
		{
			fractol->c.x = -0.7269;
			fractol->c.y = 0.1889;
			fractol->mod = input;
		}
		start_fractols(fractol);
	}
	else if (argc == 1)
		load_info_to(fractol, argc);
	set_hooks(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
