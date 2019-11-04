/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 05:45:32 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/09 22:13:57 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		length_base(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	to_base_n(unsigned int nbr, char *base, char *result, int bl)
{
	unsigned int	quotient;
	int				remainder;
	int				length;
	int				i;

	length = length_base(base);
	quotient = nbr / length;
	remainder = nbr % length;
	if (bl && quotient == 0)
		result[0] = '0';
	if (quotient != 0)
		to_base_n(quotient, base, result, 0);
	i = 0;
	while (result[i])
		i++;
	result[i] = base[remainder];
}

void	less_line(unsigned int sol, char *result)
{
	int				i;

	i = 0;
	while (i < 1000)
	{
		result[i] = '\0';
		i++;
	}
	write(1, "\\", 1);
	to_base_n(sol, "0123456789abcdef", result, 1);
	i = 0;
	while (result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned int	sol;
	char			result[1000];

	i = 0;
	while (str[i])
	{
		sol = str[i];
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			if (str[i] < 0)
				sol = str[i] + 256;
			less_line(sol, result);
		}
		i++;
	}
}
