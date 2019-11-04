/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:40:27 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/22 16:25:47 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	wrong_base(char *base)
{
	long	wrong;
	long	i;
	long	j;

	wrong = 0;
	i = 0;
	while (*(base + i))
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
				|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			wrong = 1;
		else if (*(base + i) == '+' || *(base + i) == '-')
			wrong = 1;
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				wrong = 1;
			j++;
		}
		i++;
	}
	if (i < 2)
		wrong = 1;
	return (wrong);
}

void	ft_atoi(char *nbr, char *nb, long *neg)
{
	long	i;
	long	j;

	*neg = 1;
	i = 0;
	while (nbr[i] == '\t' || nbr[i] == '\n' || nbr[i] == '\v'
			|| nbr[i] == '\f' || nbr[i] == '\r' || nbr[i] == ' ')
		i++;
	while (*(nbr + i) == '-' || *(nbr + i) == '+')
	{
		if (*(nbr + i++) == '-')
			*neg *= -1;
	}
	j = 0;
	while (*(nbr + i) && j < 34)
	{
		*(nb + j++) = *(nbr + i++);
	}
}

long	to_base_10(char *nb, char *base_from, long i, long *power)
{
	long	k;
	long	nbr;
	long	len;

	len = 0;
	while (*(base_from + len))
		len++;
	k = 0;
	while (*(nb + i) != *(base_from + k) && *(nb + i) && *(base_from + k))
		k++;
	if (*(nb + i) && *(base_from + k))
		nbr = to_base_10(nb, base_from, i + 1, power);
	else
		return (0);
	nbr += k * *power;
	*power *= len;
	return (nbr);
}

void	to_base_n(long nbr, char *base_to, char *nb)
{
	long	quotient;
	long	remainder;
	long	len;
	long	i;

	len = 0;
	while (*(base_to + len))
		len++;
	quotient = nbr / len;
	remainder = nbr % len;
	if (quotient != 0)
		to_base_n(quotient, base_to, nb);
	i = 0;
	while (*(nb + i))
		i++;
	*(nb + i) = *(base_to + remainder);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	neg;
	char	*nb;
	long	power;
	long	res;
	long	i;

	if (base_from == NULL || base_to == NULL || nbr == NULL
			|| wrong_base(base_from) || wrong_base(base_to))
		return (NULL);
	nb = malloc(sizeof(*nb) * 34);
	if (nb == NULL)
		return (NULL);
	i = 0;
	while (i++ < 34)
		*(nb + i - 1) = '\0';
	power = 1;
	ft_atoi(nbr, nb, &neg);
	res = to_base_10(nb, base_from, 0, &power);
	while (i-- > 0)
		*(nb + 33 - i) = '\0';
	if (neg == -1)
		*nb = '-';
	to_base_n(res, base_to, nb);
	return (nb);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
