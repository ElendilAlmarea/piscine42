/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:35:55 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/19 00:05:54 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		check;

	check = 0;
	if (length <= 1)
		return (1);
	i = 0;
	while (i < (length - 1))
	{
		if ((*f)(tab[i], tab[i + 1]) < 0 && check > 0)
			return (0);
		if ((*f)(tab[i], tab[i + 1]) > 0 && check < 0)
			return (0);
		check = (*f)(tab[i], tab[i + 1]);
		i++;
	}
	return (1);
}
