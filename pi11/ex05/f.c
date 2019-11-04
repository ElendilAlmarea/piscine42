/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 06:31:00 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 20:12:02 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		the_end(void)
{
	write(2, "0\n", 2);
	return (0);
}

int		ft_atoi(char *str)
{
	int		neg;
	int		i;
	int		res;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

void	op_select(int nb1, int nb2, char op, void (**oper)(int, int))
{
	if (op == '+')
		oper[0](nb1, nb2);
	else if (op == '-')
		oper[1](nb1, nb2);
	else if (op == '*')
		oper[2](nb1, nb2);
	else if (op == '/')
		oper[3](nb1, nb2);
	else if (op == '%')
		oper[4](nb1, nb2);
	else
		write(2, "Error\n", 6);
}
