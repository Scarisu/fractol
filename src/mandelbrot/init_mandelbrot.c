/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:09:52 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/17 17:51:03 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	reset_mandelbrot_mini(t_fra *e)
{
	e->zoom = 1;
	e->ms_x = -2.1 + 0.5;
	e->ms_y = -1.2 + 0.5;
	(!(ft_strcmp(e->name, "burningship"))) ? sp_burningship(e) : 0;
	(!(ft_strcmp(e->name, "celtic_mandelbrot"))) ? sp_celtic_mandelbrot(e) : 0;
	(!(ft_strcmp(e->name, "mandelbar"))) ? sp_mandelbar(e) : 0;
	(!(ft_strcmp(e->name, "cubic_burningship"))) ? sp_cubic_burningship(e) : 0;
	(!(ft_strcmp(e->name, "perpendicular_mandelbrot"))) ?
		sp_perpendicular_mandelbrot(e) : 0;
}

void	reset_mandelbrot(t_fra *e)
{
	e->alpha = 20;
	e->mul_imax = 5;
	e->color = 0;
	e->c_on = 0;
	e->c_adj = 1;
	e->rgb = hue_color(0);
	reset_mandelbrot_mini(e);
}

void	init_mlx_mandelbrot(t_fra *e)
{
	int				i;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X, Y, "fractol");
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	e->s_on = 1;
	reset_mandelbrot(e);
}

void	init_mandelbrot(t_fra *e)
{
	all_black(e);
	e->m.x1 = -2.1;
	e->m.x2 = 0.6;
	e->m.y1 = -1.2;
	e->m.y2 = 1.2;
	e->m.imax = 10 * e->mul_imax;
	e->m.i = 0;
	e->m.x = -1;
	e->m.y = -1;
	e->m.z_r = 0;
	e->m.z_i = 0;
}
