/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndrege <ndrege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:40:06 by ndrege            #+#    #+#             */
/*   Updated: 2019/07/14 12:44:52 by ndrege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_fill(int **tab, int size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size)
	{
		y = 0;
		tab[x] = malloc(size * sizeof(int));
		if (tab[x] == 0)
			return (0);
		while (y < size)
		{
			tab[x][y] = 0;
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_init_tab(int **tab, int size, char **argv, int *i)
{
	if (ft_verif_arg(argv[1], size) && ft_fill(tab, size))
	{
		ft_arg_topfloor(tab, size, argv[1], i);
		ft_arg_sides(tab, size, argv[1], i);
		return (1);
	}
	return (0);
}
