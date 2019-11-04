/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:19:13 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/10 05:38:01 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	same_char(char *str, int *wrong_char)
{
	int	i;
	int	j;

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

int	space(char *str, int i, char *base)
{
	int	j;
	int k;

	j = i;
	while (1)
	{
		k = 0;
		while (base[k])
		{
			if (str[j] == base[k])
				return (j);
			k++;
		}
		if (str[j] == '\t' || str[j] == '\n' || str[j] == '\v')
			j++;
		else if (str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
			j++;
		else if (str[j] == '+' || str[j] == '-')
			break ;
		else
			return (-1);
	}
	return (j);
}

int	sign(char *str, int i, int *neg, char *base)
{
	int	j;
	int	k;

	*neg = 1;
	j = i;
	while (1)
	{
		k = 0;
		while (base[k])
		{
			if (str[j] == base[k])
				return (j);
			k++;
		}
		if (str[j] == '-')
			*neg *= -1;
		else if (str[j] == '+')
			*neg *= 1;
		else
			return (-1);
		j++;
	}
	return (j);
}

int	num(char *str, int i, char *base, int *power)
{
	int		k;
	long	nb;
	int		length;

	length = 0;
	while (base[length])
		length++;
	k = 0;
	while (str[i] != base[k] && str[i] && base[k])
		k++;
	if (str[i] && base[k])
		nb = num(str, i + 1, base, power);
	else
		return (0);
	nb += k * *power;
	*power *= length;
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		neg;
	long	nb;
	int		wrong_char;
	int		power;

	power = 1;
	wrong_char = 1;
	if (base[0] && base[1] && same_char(base, &wrong_char) && wrong_char)
	{
		i = 0;
		i = space(str, i, base);
		if (i < 0)
			return (0);
		i = sign(str, i, &neg, base);
		if (i < 0)
			return (0);
		nb = num(str, i, base, &power) * neg;
		return ((int)nb);
	}
	return (0);
}
