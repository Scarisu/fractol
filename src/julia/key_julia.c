/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:00 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 15:34:36 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_julia(int key, t_fra *e)
{
	int			i;
	static int	space = 1;

	if (key == ESC)
		exit(0);
	space *= (key == SPA) ? -1 : 1;
	if (space == -1)
		return (0);

	//mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);

	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
