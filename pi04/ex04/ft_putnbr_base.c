/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:42:23 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/11 08:31:04 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		same_char(char *str, int *wrong_char)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			*wrong_char = 0;
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			*wrong_char = 0;
		else if (str[i] == '+' || str[i] == '-')
			*wrong_char = 0;
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		length_base(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	to_base_n(long nbr, char *base)
{
	long	quotient;
	long	remainder;
	long	length;

	length = length_base(base);
	quotient = nbr / length;
	remainder = nbr % length;
	if (quotient != 0)
		to_base_n(quotient, base);
	write(1, &base[remainder], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		wrong_char;
	long	nb;

	wrong_char = 1;
	if (length_base(base) > 1 && same_char(base, &wrong_char) && wrong_char)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nb = ((long)nbr) * -1;
		}
		else
			nb = (long)nbr;
		to_base_n(nb, base);
	}
}
