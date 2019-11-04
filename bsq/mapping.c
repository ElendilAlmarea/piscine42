/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:24:04 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/24 22:54:30 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*ft_read(char *path, t_table *t)
{
	t_fknorm	*fn;

	if (!(fn = malloc(sizeof(*fn))))
		return (NULL);
	fn->c = 0;
	fn->fd = open(path, O_RDWR);
	if (fn->fd == -1)
		return (NULL);
	fn->count = 0;
	t->lc = 0;
	while (++fn->count)
	{
		read(fn->fd, &(fn->c), 1);
		if (fn->c >= '0' && fn->c <= '9')
			t->lc = t->lc * 10 + fn->c - 48;
		else
			break ;
	}
	while (fn->c != '\n')
		read(fn->fd, &(fn->c), 1);
	read(fn->fd, &(fn->c), 1);
	fn->i = 0;
	return (ft_fknorm(fn, path, t));
}

char		*ft_fknorm(t_fknorm *fn, char *path, t_table *t)
{
	while (fn->c != '\n')
	{
		read(fn->fd, &(fn->c), 1);
		fn->i++;
	}
	t->ln = fn->i;
	if (!(fn->buffer = malloc(sizeof(*(fn->buffer)) *
					((t->lc + 1) * (fn->i + 1) + fn->count + 4))))
		return (NULL);
	close(fn->fd);
	fn->fd = open(path, O_RDWR);
	if (fn->fd == -1)
		return (NULL);
	fn->count = read(fn->fd, fn->buffer, (t->lc + 1) *
			(fn->i + 1) + fn->count + 3);
	close(fn->fd);
	fn->buffer[fn->count] = '\0';
	return (fn->buffer);
}

int			mall_grid(char *map, t_table *t)
{
	int		counter;
	t->tab = malloc(sizeof(*(t->tab)) * (t->lc + 1) * t->ln);
	counter = 0;
	if (!(t->g = malloc(sizeof(*(t->g)) * (t->lc + 1))))
		return (0);
	if (!(t->g[0] = malloc(sizeof(**(t->g)) * (t->lc + 1))))
		return (0);
	while (counter < t->lc)
		t->g[0][counter++] = t->bar;
	t->g[1] = map;
	counter = 2;
	while (*map)
	{
		if (*map == '\n' && *(map + sizeof(*map)) != '\0')
			t->g[counter++] = map + sizeof(*map);
		map++;
	}
	return (1);
}

t_table		*check_map(char *map, t_table *t)
{
	int		i;

	i = 0;
	if (!map[i] || map[i] == '\n')
		return (NULL);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (t->ln != 0 && map[i - t->ln - 1] != '\n')
				return (NULL);
		}
		else if (map[i] != t->empty && map[i] != t->bar)
			return (NULL);
		i++;
	}
	if (!mall_grid(map, t))
		return (NULL);
	return (t);
}

t_table		*valid_map(char *map, t_table *table)
{
	int		i;

	i = 0;
	while (map[i] >= '0' && map[i] <= '9')
		i++;
	if (i == 0 || table->lc < 1 || map[i] < 32 || map[i] > 126 ||
			map[i + 1] < 32 || map[i + 1] > 126 || map[i + 2] < 32 ||
			map[i + 2] > 126 || map[i + 3] != '\n')
		return (NULL);
	table->empty = map[i];
	table->bar = map[i + 1];
	table->full = map[i + 2];
	return (check_map(map + i + 4, table));
}
