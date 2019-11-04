/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndrege <ndrege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:40:13 by ndrege            #+#    #+#             */
/*   Updated: 2019/07/14 18:52:19 by ndrege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_find_sol(int **tab, int x, int y, int size)
{
	int box;

	box = 1;
	if (y == size - 1)
	{
		if (!ft_check_lign_l(tab, x, size) || !ft_check_lign_r(tab, x, size))
			return (0);
		y = ft_increm(&x);
	}
	if (ft_checkall_col(tab, size, x))
	{
		ft_display(tab, size);
		return (1);
	}
	while (box <= size - 2 && x != size - 1)
	{
		if (ft_check_valid(tab, x, y, box))
		{
			if (ft_find_sol(tab, x, y + 1, size))
				return (1);
			tab[x][y] = 0;
		}
		box++;
	}
	return (0);
}

int		ft_checkall_col(int **tab, int size, int x)
{
	int j;

	if (x == size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			if (!ft_check_col_up(tab, j, size) || !ft_check_col_d(tab, j, size))
				return (0);
			j++;
		}
		return (1);
	}
	return (0);
}

int		ft_increm(int *x)
{
	(*x)++;
	return (1);
}
