/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:09:28 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/24 22:49:14 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			delta_count(t_table *t, t_var *v)
{
	if (v->k1 == 0 && (v->j - v->m) >= 0)
		while ((v->i + v->k1 + 1) < t->lc &&
				t->g[v->i + v->k1 + 1][v->j - v->m] != t->bar)
			v->k1++;
	if (v->k2 == 0 && (v->j + v->n + 1) < t->ln && v->mid > 2)
		while ((v->i + v->k2 + 1) < t->lc &&
				t->g[v->i + v->k2 + 1][v->j + v->n + 1] != t->bar)
			v->k2++;
	if ((v->k1 >= v->k2 || v->k1 >= v->d) && (v->j - v->m) >= 0)
	{
		if (v->mid == 2)
			v->d = v->k1;
		if (v->k1 < v->dl)
			v->dl = v->k1;
		if (v->k1 <= v->ls || (v->m + v->n) >= v->d ||
				(v->m + v->n) >= v->dl || (v->m + v->n) >= v->dr)
			return (0);
		v->m++;
		v->k1 = 0;
		return (-1);
	}
	return (1);
}

int			delta_diff_left(t_var *v)
{
	if (v->k2 < v->dr)
		v->dr = v->k2;
	if (v->k2 <= v->ls || (v->m + v->n) >= v->dl ||
			(v->m + v->n) >= v->d || (v->m + v->n) >= v->dr)
	{
		v->m--;
		v->n++;
		return (0);
	}
	v->n++;
	v->k2 = 0;
	return (1);
}

int			delta_diff_right(t_table *t, t_var *v)
{
	v->ls = v->m + v->n;
	v->s1 = v->i + 1;
	v->s2 = v->j - v->m + 1;
	while (v->s2 - 1 >= 0)
	{
		v->k1 = 0;
		while ((v->i + v->k1 + 1) < t->lc &&
				t->g[v->s1 + v->k1][v->s2 - 1] != t->bar)
			v->k1++;
		if (v->k1 >= v->ls)
			v->s2--;
		else
			return (0);
	}
	return (1);
}

void		iter_line(t_table *t, t_var *v)
{
	int		a;

	while (v->j < t->ln)
	{
		if (t->g[v->i][v->j] == t->bar)
		{
			init_var(v);
			while (v->mid++)
			{
				if (!(a = delta_count(t, v)))
					break ;
				if (((v->j + v->n + 1) < t->ln) && a == 1)
				{
					if (!delta_diff_left(v))
						break ;
				}
			else if (a == 1)
					break ;
			}
			if ((v->m + v->n) > v->ls)
				if (!(delta_diff_right(t, v)))
					break ;
		}
		v->j++;
	}
}

void		display_sol(t_table *t, t_var *v)
{
	init_t(v, t);
	while (v->i < t->lc)
	{
		v->j = 0;
		iter_line(t, v);
		v->i++;
	}
	v->i = 0;
	while (v->i < v->ls)
	{
		v->j = 0;
		while (v->j < v->ls)
		{
			t->g[v->s1 + v->i][v->s2 + v->j] = t->full;
			v->j++;
		}
		v->i++;
	}
	write(1, t->g[1], (t->lc - 1) * (t->ln + 1));
	free(v);
	free(t);
}
