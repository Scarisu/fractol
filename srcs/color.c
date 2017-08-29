/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 12:58:59 by pbernier         ###   ########.fr       */
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
	while (++xy[0] < X)
	{
		while (++xy[1] < Y)
			conv_img(xy[0], xy[1], e);
		xy[1] = -1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	hue_color(int i, t_fra *e)
{
	while (i < 0 || i >= 1530)
		i += (i < 0) ? 1530 : -1530;
	if (i <= 255)
		ft_memcpy(e->rgb, ((int[3]){255, i, 0}), sizeof(int[3]));
	else if (i <= 510)
		ft_memcpy(e->rgb, ((int[3]){510 - i, 255, 0}), sizeof(int[3]));
	else if (i <= 765)
		ft_memcpy(e->rgb, ((int[3]){0, 255, i - 510}), sizeof(int[3]));
	else if (i <= 1020)
		ft_memcpy(e->rgb, ((int[3]){0, 1020 - i, 255}), sizeof(int[3]));
	else if (i <= 1275)
		ft_memcpy(e->rgb, ((int[3]){i - 1020, 0, 255}), sizeof(int[3]));
	else if (i < 1530)
		ft_memcpy(e->rgb, ((int[3]){255, 0, 1530 - i}), sizeof(int[3]));
}
