/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:09:52 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 17:08:48 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	conv_img_tamere(int x, int y, t_fra *e)
{
	int	result;

	if (x > X || y > Y || x < 0 || y < 0)
		return ;
	result = x + (X * y);
	((t_color *)e->tamere2)[result] = e->pix;
}

void reset_img(t_fra *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	e->pix = get_color(0, 0, 0, 0);
	while (y < Y)
	{
		while (x < X)
		{
			conv_img_tamere(x, y, e);
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_mlx_mendelbrot(t_fra *e)
{
	int				i;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X, Y, e->name);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->tamere = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	e->tamere2 = mlx_get_data_addr(e->tamere, &i, &i, &i);
	reset_img(e);
}

void	init_mandelbrot(t_fra *e)
{
	e->m.i = 0;
	e->m.imax = 1000;
	e->m.x = -1;
	e->m.y = -1;
	e->m.x1 = -2.1;
	e->m.x2 = 0.6;
	e->m.y1 = -1.2;
	e->m.y2 = 1.2;
	e->m.zoom_x = X / (e->m.x2 - e->m.x1);
	e->m.zoom_y = Y / (e->m.y2 - e->m.y1);
	e->m.c_r = e->m.x / e->m.zoom_x + e->m.x1;
	e->m.c_i = e->m.y / e->m.zoom_y + e->m.y1;
	e->m.z_r = 0;
	e->m.z_i = 0;
}
