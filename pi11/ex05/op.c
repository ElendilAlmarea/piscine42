/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:22:32 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 12:08:51 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	add(int nb1, int nb2)
{
	int	res;

	res = nb1 + nb2;
	ft_putnbr(res);
}

void	sub(int nb1, int nb2)
{
	int	res;

	res = nb1 - nb2;
	ft_putnbr(res);
}

void	div(int nb1, int nb2)
{
	int	res;

	if (nb2 == 0)
		write(2, "Stop : division by zero\n", 24);
	else
	{
		res = nb1 / nb2;
		ft_putnbr(res);
	}
}

void	mult(int nb1, int nb2)
{
	int	res;

	res = nb1 * nb2;
	ft_putnbr(res);
}

void	mod(int nb1, int nb2)
{
	int	res;

	if (nb2 == 0)
		write(2, "Stop : modulo by zero\n", 22);
	else
	{
		res = nb1 % nb2;
		ft_putnbr(res);
	}
}
