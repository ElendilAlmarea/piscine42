/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:03:53 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/25 14:15:35 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		is_in_charset(char character, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (character == charset[i])
			return (42);
		i++;
	}
	return (0);
}

void	curse(char *str, char *charset, char **return_string, int index)
{
	int i[2];

	i[0] = 0;
	i[1] = -1;
	if (str[0] != '\0')
	{
		if (is_in_charset(str[0], charset))
		{
			while (str[i[0]] && is_in_charset(str[i[0]], charset))
				i[0]++;
			curse(str + i[0], charset, return_string, index);
		}
		else
		{
			while (str[i[0]] && !is_in_charset(str[i[0]], charset))
				i[0]++;
			return_string[index] = malloc(sizeof(return_string) * (i[0] + 1));
			while (++i[1] < i[0])
				return_string[index][i[1]] = str[i[1]];
			return_string[index][i[1]] = '\0';
			curse(str + i[0], charset, return_string, index + 1);
		}
	}
	else
		return_string[index] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		nbr_str;
	char	**return_string;

	index = 0;
	nbr_str = 0;
	while (str[index])
	{
		if (is_in_charset(str[index], charset))
		{
			nbr_str++;
		}
		index++;
	}
	if (!(return_string = malloc(sizeof(*return_string) * (nbr_str + 1))))
		return (NULL);
	curse(str, charset, return_string, 0);
	return (return_string);
}

int main(void)
{
	char	**argv;

	argv = ft_split("","    ");
	return (0);
}
