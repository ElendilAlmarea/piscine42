/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:51:42 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/13 01:37:42 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		greater(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (0);
		i++;
	}
	if (str1[i])
		return (1);
	return (0);
}

void	write_args(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (*(argv[i] + j))
		{
			write(1, &(*(argv[i] + j)), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*swap;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (greater(argv[i], argv[j]))
			{
				swap = argv[i];
				argv[i] = argv[j];
				argv[j] = swap;
			}
			j++;
		}
		i++;
	}
	write_args(argc, argv);
}
