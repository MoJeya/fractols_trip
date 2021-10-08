/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/08 14:47:23 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
/**
 * //TODO: set point und invers_points in einer function packen
 * TODO: fill square
*/

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_lenght)
			 + (x * data->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

int clac_len(t_point p1, t_point p2)
{
	int	len;

	len = (int)sqrt(((double)p1.x - (double)p2.x) +((double)p1.y - (double)p2.y));
	printf("%d", len);
	return (len);
}

/**
 * x und y muessen beide incrementiert werden
*/

void	draw_line(t_point p1, t_vars *my_data)
{
	int	len;

	len = 100;
	while (len)
	{
		my_mlx_pixel_put(my_data, p1.x, p1.y, 0x00FF0000);
		p1.x++;
		p1.y++;
		--len;
	}
}

void start_fractols()
{
	t_vars my_data;
	t_point p1;
	t_point p2;

	p1.x = 1920/2;
	p1.y = 1080/2;
	p2.x = p1.x + 100;
	p2.y = p1.y + 100;
	clac_len(p1, p2);
	my_data.mlx = mlx_init();
	my_data.win = mlx_new_window(my_data.mlx, 1920, 1080, "Fractols");
	my_data.img = mlx_new_image(my_data.mlx, 1920, 1080);
	my_data.addr = mlx_get_data_addr(my_data.img, &my_data.bits_per_pixel, &my_data.line_lenght, &my_data.endian);
	//? Here comes the code to put the pixels
	draw_line(p1, &my_data);
	mlx_put_image_to_window(my_data.mlx, my_data.win, my_data.img, 0, 0);
	mlx_loop(my_data.mlx);
}
