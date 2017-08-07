/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:39:43 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/07 17:46:39 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		ft_pow(int nb, int pui)
{
	double	res;

	res = 1;
	while (pui-- > 0)
		res = res * nb;
	while (pui++ < -1)
		res = res / nb;
	return (res);
}

double		ft_hypotenuse(int a, int b)
{
	return (sqrt(ft_pow(a, 2) + ft_pow(b, 2)));
}

int		*multi_complex(int fs[2], int sd[2])
{
	int		*res;
	int		tmp[4];

	res = (int *)malloc(sizeof(int) * 2);
	ft_memcpy(tmp, ((int[4]){
		fs[0] * sd[0], fs[0] * sd[1],
		fs[1] * sd[0], fs[1] * sd[1]}), sizeof(int[4]));
	ft_memcpy(res, ((int[2]){
		tmp[0] + (tmp[3] * -1),
		tmp[1] + tmp[2]}), sizeof(int[2]));
 	return (res);
}
