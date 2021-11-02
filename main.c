/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:28:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/02 16:12:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

static void	close_window(int num)
{
	exit(num);
}

static void	load_info_to(t_vars *fr)
{
	fr->img = mlx_xpm_file_to_image(fr->mlx, "./image/man.xpm",
			&fr->window_width_x, &fr->window_height_y);
	load_img(fr);
}

static void	ft_set_picker(char *argv[], t_vars *fractol, int input)
{
	input = ft_atoi(argv[1]);
	if (input == 1)
		fractol->mod = input;
	else if (input == 2)
	{
		fractol->c = fractol->p[fractol->p_cnt];
		fractol->mod = input;
	}
	else if (input == 3)
		fractol->mod = input;
	else
	{
		signal(SIGALRM, close_window);
		alarm(2);
		load_info_to(fractol);
	}
	start_fractols(fractol);
}

int	main(int argc, char *argv[])
{
	t_vars		*fractol;
	int			input;

	input = 0;
	fractol = (t_vars *)malloc(sizeof(t_vars));
	init_data(fractol);
	if (argc == 2)
		ft_set_picker(argv, fractol, input);
	else
	{
		signal(SIGALRM, close_window);
		alarm(3);
		load_info_to(fractol);
	}
	set_hooks(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
