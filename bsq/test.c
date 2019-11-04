/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:15:42 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/24 22:26:12 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define SIZE1 100
#define SIZE2 100

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[SIZE1 + 1];

	fd = open(av[1], O_RDONLY);
	read(fd, buf, SIZE1);

	while (ret)
		ret = write(1, buf, SIZE2);
}
