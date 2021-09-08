/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/08 17:30:51 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

typedef struct xy_data {
	int	size_x;
	int	size_y;
}	size_xy;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*image;
	char	*buffer;
}	t_vars;

typedef struct pixel_ar {
	int width;
	int height;
}	pixel;

void start_fractols();