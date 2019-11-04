/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:28:45 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/25 14:12:03 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*str_join(char *join, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_size;

	total_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (*(*(strs + i) + j++))
			*(join + total_size++) = *(*(strs + i) + j - 1);
		if (i < (size - 1))
		{
			j = 0;
			while (*(sep + j++))
				*(join + total_size++) = *(sep + j - 1);
		}
		i++;
	}
	*(join + total_size) = '\0';
	return (join);
}

int		tot_size(int size, char **strs)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (*(*(strs + i) + j))
		{
			k++;
			j++;
		}
		i++;
	}
	return (k);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	char	*s;

	if (strs == NULL || sep == NULL)
		return (NULL);
	s = malloc(sizeof(*s));
	s[0] = '\0';
	if (size <= 0)
		return (s);
	i = 0;
	while (*(sep + i))
		i++;
	join = malloc(sizeof(*join) * (tot_size(size, strs) + (size - 1) * i + 1));
	if (join == NULL)
		return (NULL);
	return (str_join(join, size, strs, sep));
}

#include <stdio.h>
int main (int argc, char **argv)
{
	char	*str;
	str = ft_strjoin(argc, argv, " | ");
	printf("%s\n", str);
	free(str);
	return (0);
}
