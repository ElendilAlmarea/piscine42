/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 07:49:43 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/05 10:40:16 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int	i;

	if (*str == '\0')
	{
		return (1);
	}
	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) < 65) || (*(str + i) > 122))
		{
			return (0);
		}
		else if ((*(str + i) > 90) && (*(str + i) < 97))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
