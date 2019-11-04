/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:18:57 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/26 00:14:33 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disp.h"

int		ft_write(char *buffer, int size, int len)
{
	if (size == 0)
	{
		write(1, buffer, len);
	}
	else
	{
		write(1, buffer, size);
	}
	return (0);
}

int		ft_display(char *path)
{
	int		fd;
	int		size;
	char	buffer[1000000];

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	size = read(fd, buffer, 1000000);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	return (ft_write(buffer, size, 1000000));
}
