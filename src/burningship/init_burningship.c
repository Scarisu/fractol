/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:14:58 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 08:34:57 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	reset_burningship(t_fra *e)
{
	e->zoom = 1;
	e->alpha = 20;
	e->mul_imax = 5;
	e->color = 0;
	e->c_on = 0;
	e->c_adj = 1;
	e->rgb = hue_color(0);
	e->ms_x = -2.1 + 0.5;
	e->ms_y = -1.2 + 0.5;
}

void	init_mlx_burningship(t_fra *e)
{
	int				i;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X, Y, e->name);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	e->s_on = 1;
	reset_burningship(e);
}

void	init_burningship(t_fra *e)
{
	e->b.x1 = -2.1;
	e->b.x2 = 0.6;
	e->b.y1 = -1.2;
	e->b.y2 = 1.2;
	e->b.imax = 10 * e->mul_imax;
	e->b.i = 0;
	e->b.x = -1;
	e->b.y = -1;
	e->b.z_r = 0;
	e->b.z_i = 0;
}
