/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 08:38:45 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/10 21:43:28 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_base_n(long nbr, char *base, char *result, int bl)
{
	long			quotient;
	long			remainder;
	long			length;
	long			i;

	length = 0;
	while (base[length])
		length++;
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

void	write_address(char *addr, long i)
{
	long			add;
	char			result[100];
	long			j;

	j = 0;
	while (j < 100)
	{
		result[j] = '\0';
		j++;
	}
	add = (long)&addr[i];
	to_base_n(add, "0123456789abcdef", result, 1);
	write(1, "000000", 6);
	j = 0;
	while (result[j])
	{
		write(1, &result[j], 1);
		j++;
	}
	write(1, ": ", 2);
}

void	write_hex(char *addr, long i, unsigned int size)
{
	char			result[100];
	long			j;

	j = -1;
	while (j++ < 99)
		result[j] = '\0';
	if (i > size)
		write(1, "  ", 2);
	else
	{
		to_base_n(addr[i], "0123456789abcdef", result, 1);
		j = 0;
		while (result[j])
		{
			write(1, &result[j], 1);
			j++;
		}
	}
	if (i % 2 == 1)
		write(1, " ", 1);
}

void	write_char(char *addr, long i, unsigned int size)
{
	long			j;

	j = 0;
	while (j < 16 && (j + i - 16) < size)
	{
		if (addr[j + i - 15] < 32 || addr[j + i - 15] > 126)
			write(1, ".", 1);
		else
			write(1, &addr[j + i - 15], 1);
		j++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long			i;
	char			*str;
	unsigned int	true_size;

	str = (char*)addr;
	true_size = size;
	i = 0;
	while (str[i])
		i++;
	true_size = i + 1;
	if (true_size > 0)
	{
		i = 0;
		while ((i < true_size - 1) || ((i % 16) != 0))
		{
			if (i % 16 == 0)
				write_address(str, i);
			write_hex(str, i, true_size - 1);
			if (i % 16 == 15)
				write_char(str, i, true_size - 1);
			i++;
		}
	}
	return (addr);
}
