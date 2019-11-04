/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 07:08:10 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/12 13:01:29 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_length(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	j = 0;
	len_dest = str_length(dest);
	len_src = str_length(src);
	i = len_dest;
	while (src[j] && i < (size - 1) && size != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < len_dest)
		return (size + len_src);
	return (len_dest + len_src);
}
