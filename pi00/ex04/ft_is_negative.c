/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:03:31 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/03 16:57:32 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	int		number;
	char	sign;

	number = n;
	if (number >= 0)
	{
		sign = 'P';
		write(1, &sign, 1);
	}
	else
	{
		sign = 'N';
		write(1, &sign, 1);
	}
}
