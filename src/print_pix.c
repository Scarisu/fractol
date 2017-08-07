/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:03:20 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/07 16:43:47 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	conv_img(int x, int y, t_fra *e)
{
	int	result;

	if (x > X || y > Y || x < 0 || y < 0)
		return ;
	result = x + (X * y);
	((t_color *)e->data)[result] = e->pix;
}

void	bresenham(int st[2], int en[2], t_fra *e)
{
	t_line	l;

	l.dx = abs(en[0] - st[0]);
	l.dy = abs(en[1] - st[1]);
	l.sx = st[0] < en[0] ? 1 : -1;
	l.sy = st[1] < en[1] ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (1)
	{
		if (st[0] < X && st[0] >= 0 && st[1] < Y && st[1] >= 0)
			conv_img(st[0], st[1], e);
		if (st[0] == en[0] && st[1] == en[1])
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx)
		{
			l.err -= l.dy;
			st[0] += l.sx;
		}
		if (l.e2 < l.dy)
		{
			l.err += l.dx;
			st[1] += l.sy;
		}
	}
}
