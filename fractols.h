/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/20 17:27:57 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLS_H
# define FRACTOLS_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_vars;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_fractol{
	t_vars	*my_data;
	int		max_iteration;
	t_point	max;
	t_point	min;
	t_point pos;
}	t_fractol;
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
t_vars		init_data(void);
t_point 	init_pos(int x, int y);
t_fractol	init_fractol(t_vars *my_data, t_point pos);
void		ft_zoom(int x, int y, t_fractol *frac);
void		set_hooks(t_fractol frac);
int			start_fractols(t_fractol *fractol);

#endif