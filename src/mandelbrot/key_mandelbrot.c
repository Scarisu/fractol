/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:48 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/11 16:48:24 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
	else if (key == R)
		reset_mandelbrot(e);
	else if (key == PLU)
		e->mul_imax += 1;
	else if (key == MIN)
		e->mul_imax -= 1;
	else if (key == UP)
		e->alpha += 1;
	else if (key == DOW)
		e->alpha -= 1;
	else if (key == C)
		e->color += 10;
	printf("%d - %d\n", key, e->color);
	adjust_value(e);
	all_black(e);
	mandelbrot(e);
	return (0);
}
