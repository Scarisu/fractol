/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 14:36:48 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 17:29:12 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_mandelbrot(int key, t_fra *e)
{
	if (key == ESC)
		exit(0);
	all_black(e);
	mandelbrot(e);
	return (0);
}
