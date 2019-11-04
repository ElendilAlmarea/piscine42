/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:24:07 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/13 01:19:50 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	early_ret(int nb)
{
	if (nb <= 2)
		return (2);
	return (3);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	nbr;
	int	mod;

	if (nb <= 3)
		return (early_ret(nb));
	nbr = nb - 1;
	while (1)
	{
		nbr++;
		if (nbr % 2 == 0)
			continue ;
		i = 3;
		while (i < nbr && i < 46341)
		{
			mod = nbr % i;
			if (mod == 0)
				break ;
			i += 2;
		}
		if (mod != 0 || i >= 46341)
			return (nbr);
	}
}

#include <stdio.h>
int main()
{
	int i = 0;
	int b = 2;
	int	a = 0;
	while (a < 20000000)
	{
		i = ft_find_next_prime(b);
		printf("%d ", i);
		b = i + 1;
		a++;
		if (a % 20 == 0)
			printf("\n");
	}
}
