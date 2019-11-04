/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndrege <ndrege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:07:46 by ndrege            #+#    #+#             */
/*   Updated: 2019/07/14 11:20:09 by ndrege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int		main(int argc, char **argv)
{
	int	**tab;
	int	count;
	int size;
	int	i;

	i = 0;
	if (argc == 2)
	{
		count = ft_count_arg(argv[1]);
		if (!(count % 4))
		{
			size = count / 4 + 2;
			tab = malloc(size * sizeof(int *));
			if (tab != 0)
			{
				if (!ft_init_tab(tab, size, argv, &i)
				|| !ft_find_sol(tab, 1, 1, size))
					write(1, "Error\n", 6);
			}
			return (0);
		}
	}
	write(1, "Error\n", 6);
	return (0);
}
