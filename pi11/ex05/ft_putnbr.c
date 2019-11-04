/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:06:01 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 19:43:46 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int		neg(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (nb);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return (nb);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		return (nb * -1);
	}
	else
	{
		return (nb);
	}
}

void	write_while(int *tab)
{
	int		i;
	int		first_non_0;

	first_non_0 = 48;
	i = -1;
	while (i++ < 9)
	{
		if (tab[i] != 48)
		{
			first_non_0 = 49;
		}
		if (first_non_0 == 49)
		{
			write(1, &tab[i], 1);
		}
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	int		nb1;
	int		digit;
	int		i;
	int		tab[10];
	char	c;

	nb1 = neg(nb);
	if ((nb1 != -2147483648) && (nb1 != 0))
	{
		i = 10;
		while (i-- > 0)
		{
			digit = nb1 % 10;
			nb1 = (nb1 - digit) / 10;
			c = digit + 48;
			tab[i] = c;
		}
		write_while(tab);
	}
}
