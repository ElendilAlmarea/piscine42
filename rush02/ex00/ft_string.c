/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enduperv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:13:43 by enduperv          #+#    #+#             */
/*   Updated: 2019/07/21 23:34:41 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char*)malloc(ft_strlen(str) * sizeof(char));
	while (str[i])
	{
		dest[i] = str[i];
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(char *str, unsigned int size)
{
	char				*dest;
	unsigned int		i;

	if (size <= 0)
	{
		dest = (char*)malloc(1 * sizeof(char));
		dest[0] = '\0';
	}
	else
	{
		i = 0;
		dest = (char*)malloc((ft_strlen(str) + 1) * sizeof(char));
		while (str[i] && i < size)
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	**ft_split(char *str, char delimiter, int *size)
{
	char	**dest;
	int		i;
	char	*head;

	*size = ft_frequence(str, delimiter) + 1;
	dest = (char**)malloc(*size * sizeof(char*));
	i = 0;
	head = str;
	while (*str)
	{
		if (*str == delimiter)
		{
			dest[i++] = ft_strndup(head, str - head);
			head = str + 1;
		}
		str++;
	}
	str--;
	if (*str == delimiter)
		dest[i] = ft_strndup(str, 0);
	else
		dest[i] = ft_strndup(head, str - head + 1);
	return (dest);
}

char	*ft_trim(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[j] && str[j] == ' ')
		j--;
	return (ft_strndup(str + i, j - i + 1));
}
