/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:28:20 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/06 12:27:26 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int nb1, int nb2)
{
	int	i;
	int	j;

	i = 0;
	while ((i++ < nb1) && (nb1 > 0) && (nb2 > 0))
	{
		j = 0;
		while (j++ < nb2)
		{
			if (((i == 1) && (j == 1)) || ((i == 1) && (j == nb2)))
				ft_putchar('o');
			else if (((i == nb1) && (j == 1)) || ((i == nb1) && (j == nb2)))
				ft_putchar('o');
			else if ((i == 1) || (i == nb1))
				ft_putchar('-');
			else if ((j == 1) || (j == nb2))
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
