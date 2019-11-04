/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 07:07:29 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/19 01:12:52 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(src + i) != '\0')
			*(dest + i) = *(src + i);
		else
		{
			while (i < n)
			{
				*(dest + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (dest);
}
