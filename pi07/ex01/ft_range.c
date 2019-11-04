/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:09:48 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/12 07:22:25 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(*tab) * (max - min));
	if (tab != NULL)
	{
		i = 0;
		while (i < (max - min))
		{
			*(tab + i) = min + i;
			i++;
		}
		return (tab);
	}
	return (NULL);
}
