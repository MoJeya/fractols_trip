/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/22 15:28:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLS_H
# define FRACTOLS_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define M_SCROLL_UP 5
# define M_SCROLL_DOWN 4
# define M_CLICK 1

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vars
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	int		max_iter;
	t_point	m_pos;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;

}	t_vars;

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void		init_data(t_vars *fractol);
t_point		init_pos(int x, int y);
void		set_hooks(t_vars *frac);
int			start_fractols(t_vars *fractol);

#endif