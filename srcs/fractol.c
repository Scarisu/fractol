/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/29 20:14:17 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	change_fractol(int key, t_fra *e)
{
	e->name = (key == KEY_1) ? "mandelbrot" : e->name;
	e->name = (key == KEY_2) ? "julia" : e->name;
	e->name = (key == KEY_3) ? "burningship" : e->name;
	e->name = (key == KEY_4) ? "celtic_mandelbrot" : e->name;
	e->name = (key == KEY_5) ? "mandelbar" : e->name;
	e->name = (key == KEY_6) ? "celtic_mandelbar" : e->name;
	e->name = (key == KEY_7) ? "cubic_burningship" : e->name;
	e->name = (key == KEY_8) ? "perpendicular_mandelbrot" : e->name;
	e->name = (key == KEY_9) ? "heart_mandelbrot" : e->name;
	if (key == KEY_1 || key == KEY_3 || key == KEY_4 || key == KEY_5 ||
		key == KEY_6 || key == KEY_7 || key == KEY_8 || key == KEY_9)
	{
		e->key_save = key;
		reset_mandelbrot_mini(e);
	}
	if (key == KEY_2)
	{
		e->key_save = key;
		reset_julia_mini(e);
	}
}

void	restart_key(int key, t_fra *e)
{
	(key != -1 && e->key_save != key) ? change_fractol(key, e) : 0;
	(!(ft_strcmp(e->name, "mandelbrot"))) ? mandelbrot(e) : 0;
	(!(ft_strcmp(e->name, "julia"))) ? julia(e) : 0;
	(!(ft_strcmp(e->name, "burningship"))) ? burningship(e) : 0;
	(!(ft_strcmp(e->name, "celtic_mandelbrot"))) ? celtic_mandelbrot(e) : 0;
	(!(ft_strcmp(e->name, "mandelbar"))) ? mandelbar(e) : 0;
	(!(ft_strcmp(e->name, "celtic_mandelbar"))) ? celtic_mandelbar(e) : 0;
	(!(ft_strcmp(e->name, "cubic_burningship"))) ? cubic_burningship(e) : 0;
	(!(ft_strcmp(e->name, "perpendicular_mandelbrot"))) ?
		perpendicular_mandelbrot(e) : 0;
	(!(ft_strcmp(e->name, "heart_mandelbrot"))) ? heart_mandelbrot(e) : 0;
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
		ft_putstr("usage : ./fractol fractol_name\n");
		ft_putstr("fractol_name : mandelbrot | julia | ");
		ft_putstr("burningship\nceltic_mandelbrot | mandelbar\n");
		ft_putstr("celtic_mandelbar | cubic_burningship\n");
		ft_putstr("perpendicular_mandelbrot | heart_mandelbrot\n");
	}
	exit(0);
}

int		fractol_name(t_fra e)
{
	int		i;
	char	**name;

	i = 8;
	name = (char **)malloc(sizeof(char *) * 9);
	name[0] = "julia";
	name[1] = "mandelbrot";
	name[2] = "burningship";
	name[3] = "celtic_mandelbrot";
	name[4] = "mandelbar";
	name[5] = "celtic_mandelbar";
	name[6] = "cubic_burningship";
	name[7] = "perpendicular_mandelbrot";
	name[8] = "heart_mandelbrot";
	while (i >= 0 && (ft_strcmp(e.name, name[i])))
		--i;
	(i == -1) ? my_error(0, e) : 0;
	free(name);
	return (i);
}

int		main(int ac, char **av)
{
	t_fra		e;
	void		*(*fra[9])(t_fra *);

	e.name = av[1];
	e.key_save = -1;
	if (ac != 2)
		my_error(1, e);
	fra[0] = (void *)&julia;
	fra[1] = (void *)&mandelbrot;
	fra[2] = (void *)&burningship;
	fra[3] = (void *)&celtic_mandelbrot;
	fra[4] = (void *)&mandelbar;
	fra[5] = (void *)&celtic_mandelbar;
	fra[6] = (void *)&cubic_burningship;
	fra[7] = (void *)&perpendicular_mandelbrot;
	fra[8] = (void *)&heart_mandelbrot;
	fra[fractol_name(e)](&e);
	mlx_loop(e.mlx);
	return (0);
}
