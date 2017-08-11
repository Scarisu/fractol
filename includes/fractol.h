/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:56:44 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/12 01:33:31 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define X 864
# define Y 768
# define ESC 53
# define SPA 49
# define PLU 69
# define MIN 78
# define UP 126
# define DOW 125
# define KEY_R 15
# define KEY_C 8

# define L_CLICK 1
//(X = 1,125 * y)
# define WHITE 0xFFFFFF

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_mendel
{
	int				x;
	int				y;
	long double		i;
	long double		imax;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		zoom_x;
	long double		zoom_y;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
}					t_mendel;

typedef struct		s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	alpha;
}					t_color;

typedef struct		s_fra
{
	char			*name;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				alpha;
	int				mul_imax;
	int				color;
	int				*rgb;
	char			*s_alpha;
	char			*s_imax;
	int				mouse_x;
	int				mouse_y;
	t_color			pix;
	t_mendel		m;
}					t_fra;

void				conv_img(int x, int y, t_fra *e);

t_color				get_color(int r, int g, int b, int a);
void				all_black(t_fra *e);
int					*hue_color(int i);

void				julia(t_fra *e);

void				mandelbrot(t_fra *e);
void				init_mlx_mendelbrot(t_fra *e);
void				init_mandelbrot(t_fra *e);
void				reset_mandelbrot(t_fra *e);
int					key_mandelbrot(int key, t_fra *e);
int					key_mouse_mandelbrot(int key, int x, int y, t_fra *e);

void				burninship(t_fra *e);

#endif
