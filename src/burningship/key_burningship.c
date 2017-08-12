/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_burningship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:33:59 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 11:30:57 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int			key_mouse_burningship(int key, int x, int y, t_fra *e)
{
	long double		tmp_mx;
	long double		tmp_my;

	tmp_mx = (long double)x;
	tmp_my = (long double)y;
	if (key == MOL_UP || key == C_LR)
	{
		e->ms_x += (tmp_mx / (X / (e->b.x2 - e->b.x1)) - 0.5) * e->zoom / 10;
		e->ms_y += (tmp_my / (Y / (e->b.y2 - e->b.y1)) - 0.5) * e->zoom / 10;
		e->zoom /= 1.1;
	}
	else if ((key == MOL_DOWN || key == C_LF) && e->zoom < 1)
	{
		e->ms_x -= (tmp_mx / (X / (e->b.x2 - e->b.x1)) - 0.5) * e->zoom / 10;
		e->ms_y -= (tmp_my / (Y / (e->b.y2 - e->b.y1)) - 0.5) * e->zoom / 10;
		e->zoom /= 0.9;
	}
	burningship(e);
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
	else if (e->c_on == 5355 || e->c_on == 0)
		e->c_adj *= -1;
}

void		position_burningship(int key, t_fra *e)
{
	if (key == KEY_LEFT)
		e->ms_x -= (e->b.x / (X / (e->b.x2 - e->b.x1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_RIGHT)
		e->ms_x += (e->b.x / (X / (e->b.x2 - e->b.x1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_UP)
		e->ms_y -= (e->b.y / (Y / (e->b.y2 - e->b.y1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_DOWN)
		e->ms_y += (e->b.y / (Y / (e->b.y2 - e->b.y1)) - 0.5) * e->zoom / 10;
	else if (key == KEY_M)
		key_mouse_burningship(MOL_UP, X / 2, Y / 2, e);
	else if (key == KEY_N)
		key_mouse_burningship(MOL_DOWN, X / 2, Y / 2, e);
}

int			key_burningship(int key, t_fra *e)
{
	if (key == ESC)
		exit(0);
	else if (key == KEY_TAB || key == C_LEFT)
		reset_burningship(e);
	else if (key == PLU)
		e->mul_imax += 1;
	else if (key == MIN)
		e->mul_imax -= 1;
	else if (key == KEY_A)
		e->alpha += 2;
	else if (key == KEY_Z)
		e->alpha -= 2;
	else if (key == KEY_C)
		e->color += 25;
	else if (key == KEY_V)
		e->c_on += 255 * e->c_adj;
	else if (key == KEY_CLEAR)
		e->s_on *= -1;
	position_burningship(key, e);
	adjust_value(e);
	burningship(e);
	return (0);
}
