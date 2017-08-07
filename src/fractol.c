/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/07 14:57:31 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		my_error(int nb, t_fra e)
{
	if (nb == 0)
	{
		ft_putstr(e.name);
		ft_putstr(" isn't a fractol\n");
	}
	(nb <= 1) ? ft_putstr("usage : ./fractol julia | mandelbrot\n") : 0;
	exit(0);
}

int		fractol_name(t_fra e)
{
	int		i;
	char	**name;

	i = 1;
	name = (char **)malloc(sizeof(char *) * 3);
	name[0] = "julia";
	name[1] = "mandelbrot";
	while (i >= 0 && (ft_strcmp(e.name, name[i])))
		--i;
	(i == -1) ? my_error(0, e) : 0;
	free(name);
	return (i);
}

void	init(t_fra *e, void *(*fra[2])(t_fra))
{
	int		i;

	fra[0] = (void *)&julia;
	fra[1] = (void *)&mandelbrot;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, X, Y, e->name);
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data = mlx_get_data_addr(e->img, &i, &i, &i);
	e->pix = get_color(244, 131, 66, 0);
}

int		main(int ac, char **av)
{
	t_fra		e;
	void		*(*fra[2])(t_fra);

	e.name = av[1];
	if (ac != 2)
		my_error(1, e);
	init(&e, fra);
	fra[fractol_name(e)](e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_hook(e.win, 2, 3, key, &e);
	mlx_loop(e.mlx);
	return (0);
}
