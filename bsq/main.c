/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:12:20 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/25 14:19:11 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	t_table	*table;
	t_var	*var;

	if (!(var = (t_var)malloc(sizeof(*var))))
		return (0);
	if (!(table = malloc(sizeof(*table))))
		return (0);
	if (argc == 1)
		return (no_args(table, var));
	else
		with_args(argv, table, var);
	return (0);
}

void	with_args(char **argv, t_table *t, t_var *var)
{
	t_fknorm	fn;

	raise_fn(&fn, argv);
	while (fn.k++ < fn.argc - 1)
	{
		if (!(fn.map = ft_read(argv[fn.k], t)))
		{
			hop(fn.k, fn.argc, 0);
			continue ;
		}
		if (!valid_map(fn.map, t))
		{
			hop(fn.k, fn.argc, 0);
			continue ;
		}
		else
			t = valid_map(fn.map, t);
		display_sol(t, var);
		if (!(var = malloc(sizeof(*var))))
			return ;
		if (!(t = malloc(sizeof(*t))))
			return ;
		hop(fn.k, fn.argc, 1);
	}
}

void	hop(int k, int argc, int mode)
{
	if (k != argc - 1 && mode)
		write(1, "\n", 1);
	else if (!mode)
	{
		write(2, "map error\n", 10);
		if (k != argc - 1)
			write(1, "\n", 1);
	}
}

void	raise_fn(t_fknorm *fn, char **argv)
{
	fn->argc = 0;
	while (argv[fn->argc])
		fn->argc++;
	fn->k = 0;
}

int		no_args(t_table *table, t_var *var)
{
	char	c;
	int		fd;
	char	*map;

	fd = open("map", O_WRONLY);
	if (fd == -1)
		return (0);
	while (read(0, &c, 1) > 0)
		write(fd, &c, 1);
	write(fd, "\0", 1);
	close(fd);
	if (!(map = ft_read("map", table)))
	{
		free(var);
		free(table);
		return (ft_putstr_zerr("map error\n"));
	}
	if (!(table = (valid_map(map, table))))
	{
		free(var);
		free(table);
		return (ft_putstr_zerr("map error\n"));
	}
	display_sol(table, var);
	return (0);
}
