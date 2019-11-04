/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 22:13:53 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/25 14:23:56 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char *charset)
{
	int j;

	j = 0;
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

void	ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
}

int		count_str(char *str, char *charset)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			while (is_in_charset(str[i], charset))
				i++;
			if (i > 0)
				i--;
		}
		if (i != 0 && is_in_charset(str[i], charset) &&
			!(is_in_charset(str[i - 1], charset)))
			k++;
		i++;
	}
	if ((k == 0 && !str[0]) || is_in_charset(str[i - 1], charset))
		return (k + 1);
	return (k + 2);
}

char	**ft_split(char *str, char *charset)
{
	int		var[4];
	char	**tab;

	var[3] = count_str(str, charset);
	if (!(tab = malloc(sizeof(*tab) * var[3])))
		return (NULL);
	var[2] = 0;
	var[0] = 0;
	while (is_in_charset(str[var[2]], charset))
		var[2]++;
	while (var[0] < var[3] - 1)
	{
		var[1] = 0;
		while (!(is_in_charset(str[var[2]], charset)) && str[var[2]])
			if (var[2]++ + var[1]++ < -2147483648)
				var[2] += 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0;
		if (!(tab[var[0]] = malloc(sizeof(**tab) * (var[1] + 1))))
			return (NULL);
		ft_strncpy(tab[var[0]], str + var[2] - var[1], var[1]);
		while (is_in_charset(str[var[2]], charset))
			var[2]++;
		var[0]++;
	}
	tab[var[0]] = NULL;
	return (tab);
}
