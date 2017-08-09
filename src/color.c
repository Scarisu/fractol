/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 17:25:48 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_color	get_color(int r, int g, int b, int a)
{
	t_color	color;

	color.blue = b;
	color.green = g;
	color.red = r;
	color.alpha = a;
	return (color);
}

void	all_black(t_fra *e)
{
	int	xy[2];

	ft_memcpy(xy, ((int[2]){-1, -1}), sizeof(int[2]));
	e->pix = get_color(0, 0, 0, 0);
	while(++xy[0] < X)
	{
		while(++xy[1] < Y)
			conv_img(xy[0], xy[1], e);
		xy[1] = -1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
