/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enduperv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:46:49 by enduperv          #+#    #+#             */
/*   Updated: 2019/07/21 23:37:26 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_number_char(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
{
	long	nbr;

	nbr = 0;
	while (*str)
	{
		if (is_number_char(*str))
			nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr);
}

int		is_valid_int(char *str)
{
	while (*str)
	{
		if (!(is_number_char(*str) || *str == ','))
			return (0);
		str++;
	}
	return (1);
}
