/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:05:58 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/04 00:58:22 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_mult(int comb[])
{
	write(1, &comb[0], 1);
	write(1, &comb[1], 1);
	write(1, " ", 1);
	write(1, &comb[2], 1);
	write(1, &comb[3], 1);
	if (!((comb[0] == 57) && (comb[1] == 56)))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	comb[4];

	comb[0] = 47;
	while (comb[0]++ < 57)
	{
		comb[1] = 47;
		while (comb[1]++ < 57)
		{
			comb[2] = 47;
			while (comb[2]++ < 57)
			{
				comb[3] = 47;
				while (comb[3]++ < 57)
				{
					if ((10 * comb[0] + comb[1]) < (10 * comb[2] + comb[3]))
					{
						write_mult(comb);
					}
				}
			}
		}
	}
}
