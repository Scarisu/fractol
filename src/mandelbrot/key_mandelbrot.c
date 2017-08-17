/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:48 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/17 15:05:35 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			key_mouse_mandelbrot(int key, int x, int y, t_fra *e)
{
	long double		tmp_mx;
	long double		tmp_my;

	tmp_mx = (long double)x;
	tmp_my = (long double)y;
	if ((key == MOL_UP || key == C_LR) && y > 0)
	{
		e->ms_x += (tmp_mx / (X / (e->m.x2 - e->m.x1)) - 0.5) * e->zoom / 10;
		e->ms_y += (tmp_my / (Y / (e->m.y2 - e->m.y1)) - 0.5) * e->zoom / 10;
		e->zoom /= 1.1;
	}
	else if ((key == MOL_DOWN || key == C_LF) && y > 0 && e->zoom < 1.2)
	{
		e->ms_x -= (tmp_mx / (X / (e->m.x2 - e->m.x1)) - 0.5) * e->zoom / 10;
		e->ms_y -= (tmp_my / (Y / (e->m.y2 - e->m.y1)) - 0.5) * e->zoom / 10;
		e->zoom /= 0.9;
	}
	restart_key(-1, e);
	return (0);
}

static void	adjust_value(t_fra *e)
{
	if (e->alpha == 256)
		e->alpha = 0;
	else if (e->alpha == -2)
		e->alpha = 254;
	else if (e->mul_imax == 0)
		e->mul_imax += 1;
	else if (e->color >= 1530)
		e->color -= 1530;
}

void		position_mandelbrot(int key, t_fra *e)
{
	if (key == KEY_LEFT)
		e->ms_x -= (e->m.x / (X / (e->m.x2 - e->m.x1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_RIGHT)
		e->ms_x += (e->m.x / (X / (e->m.x2 - e->m.x1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_UP)
		e->ms_y -= (e->m.y / (Y / (e->m.y2 - e->m.y1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_DOWN)
		e->ms_y += (e->m.y / (Y / (e->m.y2 - e->m.y1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_M)
		key_mouse_mandelbrot(MOL_UP, X / 2, Y / 2, e);
	else if (key == KEY_N)
		key_mouse_mandelbrot(MOL_DOWN, X / 2, Y / 2, e);
	else if (key == PLU)
		e->mul_imax += 1;
	else if (key == MIN)
		e->mul_imax -= 1;
	else if (key == KEY_Q)
		reset_mandelbrot_mini(e);
}

int			key_mandelbrot(int key, t_fra *e)
{
	if (key == ESC)
		exit(0);
	else if (key == KEY_TAB || key == C_LEFT)
		reset_mandelbrot(e);
	else if (key == KEY_A)
		e->alpha += 2;
	else if (key == KEY_Z)
		e->alpha -= 2;
	else if (key == KEY_C)
		e->color += 25;
	else if (key == KEY_V)
	{
		e->c_on += 255 * e->c_adj;
		if (e->c_on == 5355 || e->c_on == 0)
			e->c_adj *= -1;
	}
	else if (key == KEY_CLEAR)
		e->s_on *= -1;
	position_mandelbrot(key, e);
	adjust_value(e);
	restart_key(key, e);
	return (0);
}
