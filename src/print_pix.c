/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:03:20 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/09 15:25:23 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	conv_img(int x, int y, t_fra *e)
{
	int	result;

	if (x > X || y > Y || x < 0 || y < 0)
		return ;
	result = x + (X * y);
	((t_color *)e->data)[result] = e->pix;
}
