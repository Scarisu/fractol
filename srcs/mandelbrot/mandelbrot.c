/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:19 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/19 11:23:29 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	str_string_mandelbrot(t_fra *e)
{
	e->s_color = ft_itoa(e->c_on / 255 + 1);
	e->s_alpha = ft_itoa(e->alpha);
	e->s_imax = ft_itoa(e->m.imax);
	mlx_string_put(e->mlx, e->win, 5, 5, WHITE, "fracal : ");
	mlx_string_put(e->mlx, e->win, 90, 5, WHITE, e->name);
	mlx_string_put(e->mlx, e->win, 5, 25, WHITE, "color  : ");
	mlx_string_put(e->mlx, e->win, 90, 25, WHITE, e->s_color);
	mlx_string_put(e->mlx, e->win, 5, 45, WHITE, "alpha  : ");
	mlx_string_put(e->mlx, e->win, 90, 45, WHITE, e->s_alpha);
	mlx_string_put(e->mlx, e->win, 5, 65, WHITE, "imax   : ");
	mlx_string_put(e->mlx, e->win, 90, 65, WHITE, e->s_imax);
	free(e->s_color);
	free(e->s_alpha);
	free(e->s_imax);
}

void	calcul_mandelbrot(t_fra *e)
{
	long double		tmp;

	e->m.c_r = (e->m.x / (X / (e->m.x2 - e->m.x1)) - 0.5) * e->zoom + e->ms_x;
	e->m.c_i = (e->m.y / (Y / (e->m.y2 - e->m.y1)) - 0.5) * e->zoom + e->ms_y;
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
		init_mlx_mandelbrot(e);
	init_mandelbrot(e);
	while (++e->m.x < X)
	{
		e->m.y = -1;
		while (++e->m.y < Y)
		{
			calcul_mandelbrot(e);
			hue_color(e->c_on / e->m.imax * e->m.i + e->color, e);
			if (e->m.i >= e->m.imax)
				e->pix = get_color(0, 0, 0, 0);
			else
				e->pix = get_color(e->rgb[0], e->rgb[1], e->rgb[2],
					e->m.i * e->alpha);
			e->m.imax = 10 * e->mul_imax - log(e->zoom);
			conv_img(e->m.x, e->m.y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->s_on == 1)
		str_string_mandelbrot(e);
	mlx_hook(e->win, 2, 3, key_mandelbrot, e);
	mlx_mouse_hook(e->win, key_mouse_mandelbrot, e);
}
