/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:12:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/17 14:38:23 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	reset_julia_mini(t_fra *e)
{
	e->zoom = 1;
	e->ms_x = -1 + 0.5;
	e->ms_y = -1.2 + 0.5;
	e->j.c_r = 0.285;
	e->j.c_i = 0.01;
	e->lock = -1;
}

void	reset_julia(t_fra *e)
{
	e->alpha = 20;
	e->mul_imax = 5;
	e->color = 0;
	e->c_on = 0;
	e->c_adj = 1;
	e->rgb = hue_color(0);
	reset_julia_mini(e);
}

void	init_mlx_julia(t_fra *e)
{
	int				i;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X, Y, e->name);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	e->s_on = 1;
	reset_julia(e);
}

void	init_julia(t_fra *e)
{
	all_black(e);
	e->j.x1 = -1;
	e->j.x2 = 1;
	e->j.y1 = -1.2;
	e->j.y2 = 1.2;
	e->j.imax = 10 * e->mul_imax;
	e->j.i = 0;
	e->j.x = -1;
	e->j.y = -1;
}
