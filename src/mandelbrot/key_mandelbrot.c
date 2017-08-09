/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:48 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 17:56:38 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_mandelbrot(int key, t_fra *e)
{
	if (key == ESC)
		exit(0);
	//e->m.imax *= (key == PLU) ? 1.8 : 0;
	//e->m.imax /= (key == MIN) ? 1.8 : 0;
	e->tmp += (key == 12) ? 1 : 0;
	printf("%d ", e->tmp);
	e->alpha += (key == UP) ? 1 : 0;
	e->alpha -= (key == DOW) ? 1 : 0;
	printf("%d\n", key);
	all_black(e);
	mandelbrot(e);
	return (0);
}
