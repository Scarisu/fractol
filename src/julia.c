/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 13:03:11 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/07 17:52:05 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_fra *e)
{
	int		st[2];

	ft_memcpy(st, ((int[2]){X / 2, Y / 2}), sizeof(int[2]));
	//while (i++ < 100)
	//{
		conv_img(

			st[0],
			st[1]

			, e);
	// }


	int		*k;

	// k = multi_complex(((int[2]){1, 1}), ((int[2]){1, 1}));
	// printf("%d - %d\n", k[0], k[1]);

	k = multi_complex((int[2]){-1, 1}, (int[2]){2, 3});
	printf("[%d - %d]\n", k[0], k[1]);
	free(k);
}
