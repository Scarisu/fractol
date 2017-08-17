/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:11 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/17 18:00:19 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	str_string_julia(t_fra *e)
{
	e->s_color = ft_itoa(e->c_on / 255 + 1);
	e->s_alpha = ft_itoa(e->alpha);
	e->s_imax = ft_itoa(e->j.imax);
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

void	calcul_julia(t_fra *e)
{
	long double		tmp;

	e->j.z_r = (e->j.x / (X / (e->j.x2 - e->j.x1)) - 0.5) * e->zoom + e->ms_x;
	e->j.z_i = (e->j.y / (Y / (e->j.y2 - e->j.y1)) - 0.5) * e->zoom + e->ms_y;
	e->j.i = 0;
	while (e->j.z_r * e->j.z_r + e->j.z_i * e->j.z_i < 4 && e->j.i < e->j.imax)
	{
		tmp = e->j.z_r;
		e->j.z_r = e->j.z_r * e->j.z_r - e->j.z_i * e->j.z_i + e->j.c_r;
		e->j.z_i = 2 * e->j.z_i * tmp + e->j.c_i;
		e->j.i++;
	}
}

void	julia(t_fra *e)
{
	if (!e->win)
		init_mlx_julia(e);
	init_julia(e);
	while (++e->j.x < X)
	{
		e->j.y = -1;
		while (++e->j.y < Y)
		{
			calcul_julia(e);
			e->rgb = hue_color(e->c_on / e->j.imax * e->j.i + e->color);
			if (e->j.i >= e->j.imax)
				e->pix = get_color(0, 0, 0, 0);
			else
				e->pix = get_color(e->rgb[0], e->rgb[1], e->rgb[2],
						e->j.i * e->alpha);
			e->j.imax = 10 * e->mul_imax - log(e->zoom * 4);
			conv_img(e->j.x, e->j.y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	e->s_on == 1 ? str_string_julia(e) : 0;
	mlx_hook(e->win, 2, 3, key_julia, e);
	mlx_hook(e->win, 6, (1L << 6), motion_mouse_julia, e);
	mlx_mouse_hook(e->win, key_mouse_julia, e);
}
