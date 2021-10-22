/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:28:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/22 20:05:20 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
#include "./libft/libft.h"

int	main(void)
{
	t_vars		*fractol;


	fractol = (t_vars *)malloc(sizeof(t_vars));
	init_data(fractol);
	start_fractols(fractol);
	set_hooks(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
