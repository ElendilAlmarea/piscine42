/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndrege <ndrege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:38:24 by ndrege            #+#    #+#             */
/*   Updated: 2019/07/14 23:16:45 by ndrege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		ft_verif_arg(char *str, int size)
{
	int	i;

	i = 1;
	if (!(str[0] >= '1' && str[0] <= size + 46))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= size + 46) && str[i] != ' ')
			return (0);
		if (str[i] == ' ' && !(str[i - 1] >= '1' && str[i - 1] <= size + 46))
			return (0);
		if ((str[i] >= '1' && str[i] <= size + 46) && !(str[i - 1] == ' '))
			return (0);
		i++;
	}
	if (str[i - 1] == ' ')
		return (0);
	return (1);
}

void	ft_arg_topfloor(int **tab, int size, char *str, int *i)
{
	int	y;

	y = 1;
	while (y < size - 1)
	{
		tab[0][y] = str[*i] - '0';
		y++;
		*i = *i + 2;
	}
	y = 1;
	while (y < size - 1)
	{
		tab[size - 1][y] = str[*i] - '0';
		y++;
		*i = *i + 2;
	}
}

void	ft_arg_sides(int **tab, int size, char *str, int *i)
{
	int	x;

	x = 1;
	while (x < size - 1)
	{
		tab[x][0] = str[*i] - '0';
		x++;
		*i = *i + 2;
	}
	x = 1;
	while (x < size - 1)
	{
		tab[x][size - 1] = str[*i] - '0';
		x++;
		*i = *i + 2;
	}
}

int		ft_count_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i / 2 + 1);
}
