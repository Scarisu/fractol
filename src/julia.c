/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:11 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/08 17:46:57 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_fra *e)
{

	long double	x1 = -2.1;
	long double	x2 = 0.6;
	long double	y1 = -1.2;
	long double	y2 = 1.2;
	int		imax = 1000;

	double	zoom_x = X / (x2 - x1);
	double	zoom_y = Y / (y2 - y1);


	int		i = 0;
	long double		tmp;
	int		x = 0;
	int		y = 0;
	long double	c_r = x / zoom_x + x1;
	long double	c_i = y / zoom_y + y1;
	long double	z_r = 0;
	long double	z_i = 0;


	while (x < X)
	{
		y = 0;
		while (y < Y)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < imax)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * fabsl(z_i * tmp) + c_i;
				i++;
			}
			if (i == imax)
				e->pix = get_color(0, 0, 0, 0);
			else
			 	e->pix = get_color(244, 131, 66, 0);
			conv_img(x, y, e);
			y++;
		}
		x++;
	}
}




	// int		*k;
	//
	// // k = multi_complex(((int[2]){1, 1}), ((int[2]){1, 1}));
	// // printf("%d - %d\n", k[0], k[1]);
	//
	// k = multi_complex((int[2]){-1, 1}, (int[2]){2, 3});
	// printf("[%d - %d]\n", k[0], k[1]);
	// free(k);

	// int		max;
	// int		st[2];
	// int		*xy;
	//
	// max = 10000;
	// ft_memcpy(st, ((int[2]){X / 2, Y / 2}), sizeof(int[2]));
	// xy = (int *)malloc(sizeof(int) * 2);
	// ft_memcpy(xy, ((int[2]){1, 1}), sizeof(int[2]));
	// while (max--)
	// {
	// 	conv_img(st[0] + xy[0], st[1] + xy[1], e);
	// 	xy = multi_complex(xy, xy);
	// }
	// free(xy);
