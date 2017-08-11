/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:48 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 01:33:41 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_mouse_mandelbrot(int key, int x, int y, t_fra *e)
{
	(void)key;
	if (key == L_CLICK)
	{
		e->mouse_x = x;
		e->mouse_y = y;
	}
	printf("[%d][%d]\n", e->mouse_x, e->mouse_y);
	return (0);
}

void	adjust_value(t_fra *e)
{
	if (e->m.i * e->alpha == 510)
		e->alpha = 0;
	else if (e->m.i * e->alpha == -2)
		e->alpha = 254;
	else if (e->mul_imax == 0)
		e->mul_imax += 1;
	else if (e->color >= 1530)
		e->color -= 1530;
}

int		key_mandelbrot(int key, t_fra *e)
{
	if (key == ESC)
		exit(0);
	else if (key == KEY_R)
		reset_mandelbrot(e);
	else if (key == PLU)
		e->mul_imax += 1;
	else if (key == MIN)
		e->mul_imax -= 1;
	else if (key == UP)
		e->alpha += 1;
	else if (key == DOW)
		e->alpha -= 1;
	else if (key == KEY_C)
		e->color += 10;
	//printf("%d - %.1Lf - %.1LF - %.1LF\n", key, e->zoom, e->m.zoom_y, e->m.zoom_x);
	adjust_value(e);
	all_black(e);
	mandelbrot(e);
	return (0);
}
