/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:19 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/07 15:41:08 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fra *e)
{
	int		st[2];
	int		x = 0;
	int		y = 0;
	int		i = 0;

	ft_memcpy(st, ((int[2]){X - X / 3, Y / 2}), sizeof(int[2]));
	while (i++ < 100)
	{
		conv_img(st[0] + x++, st[1] + y++, e);
	}
	x += 0;
	e += 0;
}
