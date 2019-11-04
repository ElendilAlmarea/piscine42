/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 07:23:09 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/22 16:17:16 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(tab = malloc(sizeof(*tab) * (max - min))))
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		*(tab + i) = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}
