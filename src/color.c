/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:07:31 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 15:25:07 by pbernier         ###   ########.fr       */
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

// int		*hue_color(int r, int g, int b, int i)
// {
//
// }
