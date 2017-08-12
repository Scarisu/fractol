/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:31:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 08:40:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	str_string_burningship(t_fra *e)
{
	e->s_color = ft_itoa(e->c_on / 255 + 1);
	e->s_alpha = ft_itoa(e->alpha);
	e->s_imax = ft_itoa(e->b.imax);
	mlx_string_put(e->mlx, e->win, 5, 5, WHITE, "color : ");
	mlx_string_put(e->mlx, e->win, 80, 5, WHITE, e->s_color);
	mlx_string_put(e->mlx, e->win, 5, 25, WHITE, "alpha : ");
	mlx_string_put(e->mlx, e->win, 80, 25, WHITE, e->s_alpha);
	mlx_string_put(e->mlx, e->win, 5, 45, WHITE, "imax  : ");
	mlx_string_put(e->mlx, e->win, 80, 45, WHITE, e->s_imax);
	free(e->s_color);
	free(e->s_alpha);
	free(e->s_imax);
}

void	calcul_burningship(t_fra *e)
{
	long double		tmp;

	e->b.c_r = (e->b.x / (X / (e->b.x2 - e->b.x1)) - 0.5) * e->zoom + e->ms_x;
	e->b.c_i = (e->b.y / (Y / (e->b.y2 - e->b.y1)) - 0.5) * e->zoom + e->ms_y;
	e->b.z_r = 0;
	e->b.z_i = 0;
	e->b.i = 0;
	while (e->b.z_r * e->b.z_r + e->b.z_i * e->b.z_i < 4 && e->b.i < e->b.imax)
	{
		tmp = e->b.z_r;
		e->b.z_r = e->b.z_r * e->b.z_r - e->b.z_i * e->b.z_i + e->b.c_r;
		e->b.z_i = 2 * fabsl(e->b.z_i * tmp) + e->b.c_i;
		e->b.i++;
	}
}

void	burningship(t_fra *e)
{
	if (!e->win)
		init_mlx_burningship(e);
	all_black(e);
	init_burningship(e);
	while (++e->b.x < X)
	{
		e->b.y = -1;
		while (++e->b.y < Y)
		{
			calcul_burningship(e);
			e->rgb = hue_color(e->c_on / e->b.imax * e->b.i + e->color);
			if (e->b.i >= e->b.imax)
				e->pix = get_color(0, 0, 0, 0);
			else
				e->pix = get_color(e->rgb[0], e->rgb[1], e->rgb[2],
					e->b.i * e->alpha);
			e->b.imax = 10 * e->mul_imax - log(e->zoom * 4);
			conv_img(e->b.x, e->b.y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->s_on == 1)
		str_string_burningship(e);
	mlx_hook(e->win, 2, 3, key_burningship, e);
	mlx_mouse_hook(e->win, key_mouse_burningship, e);
}
