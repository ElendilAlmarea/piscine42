/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:43:54 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/07 03:05:09 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	pos(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int				ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	i1;
	unsigned int	i2;

	i = 0;
	while (i < n)
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
	return (0);
}
