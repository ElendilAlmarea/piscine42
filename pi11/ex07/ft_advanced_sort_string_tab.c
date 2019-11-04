/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:16:06 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/21 00:56:10 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		k;
	char	*swap;

	k = 0;
	while (tab[k++])
	{
		i = 0;
		while (tab[i])
		{
			j = i + 1;
			while (tab[j])
			{
				if ((*cmp)(tab[i], tab[j]) > 0)
				{
					swap = tab[i];
					tab[i] = tab[j];
					tab[j] = swap;
				}
				j++;
			}
			i++;
		}
	}
}
