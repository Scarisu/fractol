/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:48 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 17:08:03 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_mandelbrot(int key, t_fra *e)
{
	// int			i;

	key += 0;
	// mlx_destroy_image(e->mlx, e->img);
	// e->img = mlx_new_image(e->mlx, X, Y);
	// e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	mandelbrot(e);
	return (0);
}
