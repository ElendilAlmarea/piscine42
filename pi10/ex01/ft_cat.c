/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:18:57 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/17 13:00:06 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *str, int i)
{
	return (str[i] ? ft_strlen(str, i + 1) : i);
}

void	write_input(void)
{
	char	c;

	while (read(0, &c, 1) > 0)
		write(1, &c, 1);
}

void	main_second(int argc, char **argv)
{
	int			fd;
	int			i;
	size_t		size;
	char		buffer[28000];

	i = 0;
	while (i++ < argc - 1)
	{
		fd = open(argv[i], O_RDWR);
		if (fd < 0)
		{
			write(2, "cat: ", 5);
			write(2, argv[i], ft_strlen(argv[i], 0));
			if (errno == 21)
				write(2, ": Is a directory\n", 17);
			else
				write(2, ": No such file or directory\n", 28);
			continue ;
		}
		while ((size = read(fd, &buffer, 28000)))
			write(1, &buffer, size);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write_input();
	else
		main_second(argc, argv);
	return (0);
}
