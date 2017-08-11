/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:19 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 01:28:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	str_string(t_fra *e)
{
	e->s_alpha = ft_itoa(e->m.i * e->alpha);
	e->s_imax = ft_itoa(e->m.imax);
	mlx_string_put(e->mlx, e->win, 5, 5, WHITE, "alpha : ");
	mlx_string_put(e->mlx, e->win, 80, 5, WHITE, e->s_alpha);
	mlx_string_put(e->mlx, e->win, 5, 25, WHITE, "imax  : ");
	mlx_string_put(e->mlx, e->win, 80, 25, WHITE, e->s_imax);
	free(e->s_alpha);
	free(e->s_imax);
}

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
					e->pix = get_color(e->rgb[0], e->rgb[1], e->rgb[2],
						e->m.i * e->alpha);
			conv_img(e->m.x, e->m.y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	str_string(e);
	mlx_hook(e->win, 2, 3, key_mandelbrot, e);
	mlx_mouse_hook(e->win, key_mouse_mandelbrot, e);
}
