/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:01:58 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/19 12:14:38 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	pos(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int				ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	i1;
	unsigned int	i2;

	i = 0;
	while (1)
	{
		i1 = pos(*(s1 + i));
		i2 = pos(*(s2 + i));
		if (i1 < i2)
			return (i1 - i2);
		else if (i1 > i2)
			return (i1 - i2);
		else if ((i1 == '\0') && (i2 == '\0'))
			return (0);
		i++;
	}
}

void			ft_sort_string_tab(char **tab)
{
	int			i;
	int			j;
	char		*swap;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
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
