/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/06 20:24:17 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniLibx/mlx.h"
#include "miniLibx/mlx_int.h"
#include "miniLibx/mlx_new_window.h"
#include "miniLibx/mlx_opengl.h"
#include "miniLibx/mlx_png.h"
#include "libft/libft.h"

typedef struct xy_data {
	int	size_x;
	int	size_y;
}	size_xy;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;