/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enduperv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:23:21 by enduperv          #+#    #+#             */
/*   Updated: 2019/07/21 18:27:57 by enduperv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_suffix(int n, char *suffix)
{
	if (n && suffix[0])
	{
		ft_putchar(' ');
		ft_putstr(suffix);
	}
}

void	num_to_words(int n, char *suffix, t_dict *dict)
{
	int	nbr;

	nbr = n;
	if (n >= 100)
	{
		ft_putstr(dict->one[n / 100]);
		ft_putchar(' ');
		ft_putstr(dict->other[0]);
		nbr = n % 100;
	}
	if (n >= 100 && nbr > 0)
		ft_putstr(" and ");
	if (nbr > 19)
	{
		ft_putstr(dict->ten[nbr / 10]);
		if (nbr % 10 > 0)
		{
			ft_putchar(' ');
			ft_putstr(dict->one[nbr % 10]);
		}
	}
	else if (nbr > 0)
		ft_putstr(dict->one[nbr]);
	print_suffix(n, suffix);
}

void	convert_to_words(unsigned long n, t_dict *dict)
{
	int num0;
	int	num1;
	int	num2;
	int	num3;

	num0 = n / 1000000000000;
	num_to_words(num0, dict->other[4], dict);
	num1 = (n / 1000000000) % 1000;
	if (num0 > 0 && num1 > 0)
		ft_putchar(' ');
	num_to_words(num1, dict->other[3], dict);
	num2 = (n / 1000000) % 1000;
	if ((num0 > 0 || num1 > 0) && num2 > 0)
		ft_putchar(' ');
	num_to_words(num2, dict->other[2], dict);
	num3 = (n / 1000) % 1000;
	if ((num0 > 0 || num1 > 0 || num2 > 0) && num3 > 0)
		ft_putchar(' ');
	num_to_words(num3, dict->other[1], dict);
	if (n > 1000 && n % 1000)
		ft_putchar(' ');
	num_to_words(n % 1000, "", dict);
	ft_putchar('\n');
}

int		run_convert(int dictionary, unsigned long nbr)
{
	char	buff[1000000];
	t_dict	dict;
	int		size;

	size = read(dictionary, buff, 1000000);
	buff[size] = '\0';
	if (!is_valid_dictionary(buff))
		return (0);
	parse_dictionary(buff, &dict);
	if (nbr == 0)
	{
		ft_putstr(dict.one[0]);
		ft_putchar('\n');
	}
	else
		convert_to_words(nbr, &dict);
	return (1);
}
