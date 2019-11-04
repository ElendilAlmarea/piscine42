/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 03:17:55 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/12 12:54:53 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	len = 0;
	if (to_find[0] == '\0')
		return (str);
	while (to_find[len])
		len++;
	while (str[i])
	{
		j = i;
		k = 0;
		while (to_find[k] == str[j])
		{
			if (k == (len - 1))
				return (str + i);
			k++;
			j++;
		}
		i++;
	}
	return (0);
}
