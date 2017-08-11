/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:22:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/11 16:31:36 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "./libft/includes/libft.h"

int		*hue_color(int i)
{
	int *tab_c;

	if (!(tab_c = (int *)malloc(sizeof(int) * 3)))
		exit(-1);
	while (i < 0 || i > 1530)
		i += (i < 0) ? 1530 : -1530;
	if (i <= 255)
		ft_memcpy(tab_c, ((int[3]){255, i, 0}), sizeof(int[3]));
	else if (i <= 510)
		ft_memcpy(tab_c, ((int[3]){510 - i, 255, 0}), sizeof(int[3]));
	else if (i <= 765)
		ft_memcpy(tab_c, ((int[3]){0, 255, i - 510}), sizeof(int[3]));
	else if (i <= 1020)
		ft_memcpy(tab_c, ((int[3]){0, 1020 - i, 255}), sizeof(int[3]));
	else if (i <= 1275)
		ft_memcpy(tab_c, ((int[3]){i - 1020, 0, 255}), sizeof(int[3]));
	else if (i <= 1530)
		ft_memcpy(tab_c, ((int[3]){255, 0, 1530 - i}), sizeof(int[3]));
	return (tab_c);
}

int		main(void)
{
	int		*tab;
	int		i = -80;
	int		tmp = 0;

	while (++i <= 1780)
	{
		if (i <= 0 || i == 1 || i == 2
					|| (i >= 253 && i <= 257 ) || (i >= 508 && i <= 512)
					|| (i >= 763 && i <= 767) || (i >= 1018 && i <= 1022)
					|| (i >= 1273 && i <= 1277) || (i >= 1528 && i <= 1532)
					|| (i >= 1778 && i <= 1783))
		{
			tab = hue_color(i);
			printf("%d = [%d][%d][%d]\n", i, tab[0], tab[1], tab[2]);
			free(tab);
			tmp = 1;
		}
		else if (tmp == 1)
		{
			tmp = 0;
			printf("\n");
		}

	}
	return (0);
}
