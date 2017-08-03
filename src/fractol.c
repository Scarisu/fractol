/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/03 18:08:20 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key(int key, t_fdf *e)
{
	int			i;
	static int	space = 1;

	if (key == 53)
		exit(0);
	space *= (key == 49) ? -1 : 1;
	if (space == -1)
		return (0);

	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);

	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

t_color	get_color(int r, int g, int b, int a)
{
	t_color	color;

	color.blue = b;
	color.green = g;
	color.red = r;
	color.alpha = a;
	return (color);
}

void	init(t_fra *e, char *name, int fd)
{
	int		i;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X, Y, name);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	e->pix = get_color(244, 131, 66, 0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_fra		e;

	if (ac != 2 ||(fd = open(av[1], O_RDONLY)) <= 0)
		return (-1);
	init(&e, av[1], fd);

	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_hook(e.win, 2, 3, key, &e);
	mlx_loop(e.mlx);
	return (0);
}
