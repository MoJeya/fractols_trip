/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:45:02 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/09/06 20:26:27 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractols.h"

int main(void)
{
	char	*title;
	size_xy sizes;
	t_vars vars;

	title = ft_strdup("Fractols");
	sizes.size_x = 250;
	sizes.size_x = 250;
	vars.mlx = mlx_init();
	vars.win = (vars.mlx, sizes.size_x, sizes.size_y, title);
	return (0);
}