/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:19 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 17:44:32 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	calcul_mandelbrot(t_fra *e)
{
	long double		tmp;

	e->m.c_r = e->m.x / e->m.zoom_x + e->m.x1;
	e->m.c_i = e->m.y / e->m.zoom_y + e->m.y1;
	e->m.z_r = 0;
	e->m.z_i = 0;
	e->m.i = 0;
	while (e->m.z_r * e->m.z_r + e->m.z_i * e->m.z_i < 4 && e->m.i < e->m.imax)
	{
		tmp = e->m.z_r;
		e->m.z_r = e->m.z_r * e->m.z_r - e->m.z_i * e->m.z_i + e->m.c_r;
		e->m.z_i = 2 * e->m.z_i * tmp + e->m.c_i;
		e->m.i++;
	}
}

void	mandelbrot(t_fra *e)
{
	if (!e->win)
		init_mlx_mendelbrot(e);
	init_mandelbrot(e);
	while (++e->m.x < X)
	{
		e->m.y = -1;
		while (++e->m.y < Y)
		{
			calcul_mandelbrot(e);
			if (e->m.i == e->m.imax)
				e->pix = get_color(0, 0, 0, 0);
			else
					e->pix = get_color(100, 131, 66, e->m.i * e->alpha);
			conv_img(e->m.x, e->m.y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, key_mandelbrot, e);
}
