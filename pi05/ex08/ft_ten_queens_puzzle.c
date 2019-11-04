/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:36:17 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/13 18:40:41 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fill(int *tab, int c, int l, int neg)
{
	int	i;

	tab[c * 10 + l] += neg;
	i = 1;
	while (i < 10)
	{
		tab[c * 10 + i] += neg;
		tab[i * 10 + l] += neg;
		if ((c + i) < 10 && (l + i) < 10)
			tab[(c + i) * 10 + l + i] += neg;
		if ((c + i) < 10 && (l - i) >= 0)
			tab[(c + i) * 10 + l - i] += neg;
		if ((c - i) >= 0 && (l - i) >= 0)
			tab[(c - i) * 10 + l - i] += neg;
		if ((c - i) >= 0 && (l + i) < 10)
			tab[(c - i) * 10 + l + i] += neg;
		i++;
	}
}

void	write_sol(int *sol, int *nb_sol)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		sol[i] += 48;
		write(1, &sol[i], 1);
		sol[i] -= 48;
		i++;
	}
	write(1, "\n", 1);
	(*nb_sol)++;
}

void	tenq(int *tab, int *sol, int c, int *nb_sol)
{
	int	l;

	l = 0;
	while (l < 10)
	{
		if (tab[c * 10 + l] == 0)
		{
			sol[c] = l;
			fill(tab, c, l, 1);
			if (c == 9)
				write_sol(sol, nb_sol);
			else
				tenq(tab, sol, c + 1, nb_sol);
			fill(tab, c, l, -1);
		}
		l++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int	tab[100];
	int	sol[10];
	int	i;
	int	nb_sol;

	nb_sol = 0;
	i = 0;
	while (i < 100)
	{
		if (i < 10)
			sol[i] = 0;
		tab[i] = 0;
		i++;
	}
	tenq(tab, sol, 0, &nb_sol);
	return (nb_sol);
}
