/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:06:03 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/04 11:38:03 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		end(int tab[], int lentab)
{
	int	i;
	int	sum1;
	int	sum2;

	i = -1;
	sum1 = 0;
	sum2 = 0;
	while (i++ < lentab - 1)
	{
		sum1 += tab[i];
		sum2 += 57 - i;
	}
	if (sum1 == sum2)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int		increasing(int tab[], int lentab)
{
	int	i;
	int	inc;

	i = -1;
	inc = 1;
	while (i++ < lentab - 2)
	{
		if (tab[i] >= tab[i + 1])
		{
			inc = 0;
			break ;
		}
	}
	if (inc == 1)
	{
		inc = end(tab, lentab);
	}
	return (inc);
}

void	ft_print_combn_2(int n, int tab[], int lentab)
{
	int	nb;
	int	i;

	nb = 47;
	while (nb++ < 57)
	{
		tab[lentab - n] = nb;
		if (n > 1)
		{
			ft_print_combn_2(n - 1, tab, lentab);
		}
		else
		{
			if (increasing(tab, lentab))
			{
				i = -1;
				while (i++ < lentab - 1)
				{
					write(1, &tab[i], 1);
				}
				write(1, ", ", 2);
			}
		}
	}
}

void	ft_print_combn(int n)
{
	int	tab[n];
	int	lentab;
	int	i;
	int	display;

	lentab = n;
	ft_print_combn_2(n, tab, lentab);
	i = -1;
	while (i++ < lentab - 1)
	{
		display = 58 - lentab + i;
		write(1, &display, 1);
	}
}
