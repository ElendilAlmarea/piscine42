/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndrege <ndrege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:38:04 by ndrege            #+#    #+#             */
/*   Updated: 2019/07/14 16:15:19 by ndrege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_valid(int **tab, int x, int y, int nb)
{
	int	i;
	int	j;

	j = 1;
	while (j < y)
	{
		if (tab[x][j] == nb)
			return (0);
		j++;
	}
	i = 1;
	while (i < x)
	{
		if (tab[i][y] == nb)
			return (0);
		i++;
	}
	tab[x][y] = nb;
	return (1);
}

int	ft_check_lign_l(int **tab, int x, int size)
{
	int	j;
	int	count;
	int	max;

	j = 2;
	count = 1;
	max = tab[x][1];
	while (j < size - 1)
	{
		if (tab[x][j] > max)
		{
			max = tab[x][j];
			count++;
		}
		j++;
	}
	if (count == tab[x][0])
		return (1);
	return (0);
}

int	ft_check_col_up(int **tab, int y, int size)
{
	int	i;
	int	count;
	int	max;

	i = 2;
	count = 1;
	max = tab[1][y];
	while (i < size - 1)
	{
		if (tab[i][y] > max)
		{
			max = tab[i][y];
			count++;
		}
		i++;
	}
	if (count == tab[0][y])
		return (1);
	return (0);
}

int	ft_check_col_d(int **tab, int y, int size)
{
	int	i;
	int	count;
	int	max;

	i = size - 3;
	count = 1;
	max = tab[size - 2][y];
	while (i > 0)
	{
		if (tab[i][y] > max)
		{
			max = tab[i][y];
			count++;
		}
		i--;
	}
	if (count == tab[size - 1][y])
		return (1);
	return (0);
}

int	ft_check_lign_r(int **tab, int x, int size)
{
	int	j;
	int	count;
	int	max;

	j = size - 3;
	count = 1;
	max = tab[x][size - 2];
	while (j > 0)
	{
		if (tab[x][j] > max)
		{
			max = tab[x][j];
			count++;
		}
		j--;
	}
	if (count == tab[x][size - 1])
		return (1);
	return (0);
}
