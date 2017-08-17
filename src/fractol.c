/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/17 12:00:48 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		restart_key(t_fra *e)
{
	if (ft_strcmp(e->name, "mandelbrot") == 0)
		mandelbrot(e);
	else if (ft_strcmp(e->name, "burningship") == 0)
		burningship(e);
	else if (ft_strcmp(e->name, "celtic_mandelbrot") == 0)
		celtic_mandelbrot(e);
	else if (ft_strcmp(e->name, "mandelbar") == 0)
		mandelbar(e);
	else if (ft_strcmp(e->name, "celtic_mandelbar") == 0)
	 	celtic_mandelbar(e);
	else if (ft_strcmp(e->name, "cubic_burningship") == 0)
		cubic_burningship(e);
}

void	my_error(int nb, t_fra e)
{
	if (nb == 0)
	{
		ft_putstr(e.name);
		ft_putstr(" isn't a fractol\n");
	}
	if (nb <= 1)
	{
		ft_putstr("usage : ./fractol julia | mandelbrot | ");
		ft_putstr("burningship | celtic_mandelbrot | mandelbar | ");
		ft_putstr("celtic_mandelbar | cubic_burningship\n");
	}
	exit(0);
}

int		fractol_name(t_fra e)
{
	int		i;
	char	**name;

	i = 6;
	name = (char **)malloc(sizeof(char *) * 7);
	name[0] = "julia";
	name[1] = "mandelbrot";
	name[2] = "burningship";
	name[3] = "celtic_mandelbrot";
	name[4] = "mandelbar";
	name[5] = "celtic_mandelbar";
	name[6] = "cubic_burningship";
	while (i >= 0 && (ft_strcmp(e.name, name[i])))
		--i;
	(i == -1) ? my_error(0, e) : 0;
	free(name);
	return (i);
}

int		main(int ac, char **av)
{
	t_fra		e;
	void		*(*fra[7])(t_fra *);

	e.name = av[1];
	if (ac != 2)
		my_error(1, e);
	fra[0] = (void *)&julia;
	fra[1] = (void *)&mandelbrot;
	fra[2] = (void *)&burningship;
	fra[3] = (void *)&celtic_mandelbrot;
	fra[4] = (void *)&mandelbar;
	fra[5] = (void *)&celtic_mandelbar;
	fra[6] = (void *)&cubic_burningship;
	fra[fractol_name(e)](&e);
	mlx_loop(e.mlx);
	return (0);
}
