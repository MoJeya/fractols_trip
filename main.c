/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:28:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/29 16:51:12 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

int	ft_atoi(const char *str);

int	main(int argc, char *argv[])
{
	t_vars		*fractol;
	int			input;

	input = 0;
	fractol = (t_vars *)malloc(sizeof(t_vars));
	if (argc == 2)
	{
		ft_putstr_fd("The argument supplied is 2", 1);
		input = ft_atoi(argv[1]);
	}
	else if (argc > 2)
		printf("There are to many arguments supplied.\n");
	else
	{
		
		printf("One argument expected.\n");
	}
	init_data(fractol);
	if (input == 1)
		fractol->mod = input;
	if (input == 2)
	{
		fractol->c.x = -0.7269;
		fractol->c.y = 0.1889;
		fractol->mod = input;
	}
	start_fractols(fractol);
	set_hooks(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
