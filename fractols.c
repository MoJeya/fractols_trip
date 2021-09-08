/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/08 17:28:01 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"
void start_fractols()
{
	size_xy	sizes;
	t_vars	v;
	int	pixel_bits;
	int line_bytes;
	int endian;

	sizes.size_x = 640;
	sizes.size_x = 360;
	pixel_bits = 0;
	line_bytes = 0;
	endian = 0;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, sizes.size_x, sizes.size_y, "Fractols");
	v.image = mlx_new_image(v.mlx, sizes.size_x, sizes.size_y);
	v.buffer = mlx_get_data_addr(v.image, &pixel_bits, &line_bytes, &endian);
	mlx_loop(v.mlx);
}
