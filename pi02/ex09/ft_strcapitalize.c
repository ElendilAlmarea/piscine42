/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 11:12:38 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/06 01:57:45 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			cap_alphanum(char *str, int cap, int i)
{
	if ((*(str + i) > 47) && (*(str + i) < 58))
	{
		return (0);
	}
	else if ((*(str + i) > 64) && (*(str + i) < 91))
	{
		*(str + i) = (cap) ? *(str + i) : (*(str + i) + 32);
		return (0);
	}
	else if ((*(str + i) > 96) && (*(str + i) < 123))
	{
		*(str + i) = (cap) ? (*(str + i) - 32) : *(str + i);
		return (0);
	}
	else
	{
		return (1);
	}
}

char		*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;

	i = 0;
	cap = 1;
	while (*(str + i) != '\0')
	{
		cap = (cap_alphanum(str, cap, i));
		i++;
	}
	return (str);
}
