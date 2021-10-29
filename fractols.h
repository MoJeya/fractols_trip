/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/10/29 18:36:45 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLS_H
# define FRACTOLS_H

# include "mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define M_SCROLL_UP 5
# define M_SCROLL_DOWN 4
# define ML_CLICK 1
# define MR_CLICK 2
# define WINDOW_X 400
# define WINDOW_Y 400
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_PLUS 69
# define KEY_MINUS 78
# define COLOR_KEY 8
# define KEY_ESC 53

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_vars
{
	int			mod;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	t_point		c;
	int			window_width_x;
	int			window_height_y;
	t_point		m_pos;
	t_point		img_val;
	t_point		range;
	int			max_iter;
	double		max_calc;
	int			color_shift;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;

}	t_vars;

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
void		init_data(t_vars *fractol);
double		inter_pol(double start, double end, double inter);
t_point		init_pos(int x, int y);
void		set_hooks(t_vars *frac);
int			mandel_loop(double x, double y, t_vars *fractol);
int			julia_loop(double x, double y, t_vars *fractol);
void		load_img(t_vars *fr);
int			start_fractols(t_vars *fr);

#endif