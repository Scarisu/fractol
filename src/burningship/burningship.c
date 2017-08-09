/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:31:56 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 15:23:51 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_burningship(t_fra *e, t_mendel *m)
{
	e += 0;
	m->i = 0;
	m->imax = 1000;
	m->x = -1;
	m->y = -1;
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->zoom_x = X / (m->x2 - m->x1);
	m->zoom_y = Y / (m->y2 - m->y1);
	m->c_r = m->x / m->zoom_x + m->x1;
	m->c_i = m->y / m->zoom_y + m->y1;
	m->z_r = 0;
	m->z_i = 0;
}

void	calcul_burningship(t_fra *e, t_mendel *m)
{
	long double		tmp;

	e += 0;
	m->c_r = m->x / m->zoom_x + m->x1;
	m->c_i = m->y / m->zoom_y + m->y1;
	m->z_r = 0;
	m->z_i = 0;
	m->i = 0;
	while ((m->z_r * m->z_r + m->z_i * m->z_i) < 4 && m->i < m->imax)
	{
		tmp = m->z_r;
		m->z_r = m->z_r * m->z_r - m->z_i * m->z_i + m->c_r;
		m->z_i = 2 * m->z_i * tmp + m->c_i;
		m->i++;
	}
}

void	burningship(t_fra *e)
{
	t_mendel		m;

	init_burningship(e, &m);
	while (++m.x < X)
	{
		m.y = -1;
		while (++m.y < Y)
		{
			calcul_burningship(e, &m);
			if (m.i == m.imax)
				e->pix = get_color(0, 0, 0, 0);
			else
			{
				//printf("[%d - %d] = %d\n", m.x, m.y, m.i);
			 	e->pix = get_color(255, 131, 66, m.i * 10);
			}
			conv_img(m.x, m.y, e);
		}
	}
}
