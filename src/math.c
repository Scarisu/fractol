/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:39:43 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/07 16:47:13 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_pow(int nb, int pow)
{
	int		res;

	res = 1;
	while (pow-- > 1)
		res = res * nb;
	return (res);
}

// int		*multi_complex(int fs[2], int sd[2])
// {
// 	int		res[2];
// 	int		hyp;
//
// 	hyp = sqrt();
//
// 	return ((int *)res);
// }
