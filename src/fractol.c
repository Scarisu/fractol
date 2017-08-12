/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 07:34:00 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	my_error(int nb, t_fra e)
{
	if (nb == 0)
	{
		ft_putstr(e.name);
		ft_putstr(" isn't a fractol\n");
	}
	if (nb <= 1)
		ft_putstr("usage : ./fractol julia | mandelbrot | burningship\n");
	exit(0);
}

int		fractol_name(t_fra e)
{
	int		i;
	char	**name;

	i = 2;
	name = (char **)malloc(sizeof(char *) * 3);
	name[0] = "julia";
	name[1] = "mandelbrot";
	name[2] = "burningship";
	while (i >= 0 && (ft_strcmp(e.name, name[i])))
		--i;
	(i == -1) ? my_error(0, e) : 0;
	free(name);
	return (i);
}

int		main(int ac, char **av)
{
	t_fra		e;
	void		*(*fra[3])(t_fra *);

	e.name = av[1];
	if (ac != 2)
		my_error(1, e);
	fra[0] = (void *)&julia;
	fra[1] = (void *)&mandelbrot;
	fra[2] = (void *)&burningship;
	fra[fractol_name(e)](&e);
	mlx_loop(e.mlx);
	return (0);
}
