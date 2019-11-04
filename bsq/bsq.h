/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:08:25 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/24 22:56:46 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_table	t_table;

struct				s_table
{
	int				**tab;
	char			**g;
	int				ln;
	int				lc;
	char			empty;
	char			bar;
	char			full;
};

typedef struct s_var	t_var;

struct				s_var
{
	int				i;
	int				j;
	int				k1;
	int				k2;
	int				m;
	int				n;
	int				ls;
	int				d;
	int				dl;
	int				dr;
	int				mid;
	int				s1;
	int				s2;
};

typedef struct s_fknorm	t_fknorm;

struct				s_fknorm
{
	int				fd;
	char			*buffer;
	int				count;
	int				i;
	char			c;
	int				argc;
	int				k;
	char			*map;
};

t_table				*valid_map(char *map, t_table *table);
t_table				*check_map(char *map, t_table *table);
char				*ft_read(char *path, t_table *t);
char				*ft_fknorm(t_fknorm *fn, char *path, t_table *t);
char				*ft_strcpy(char *dest, char *src);
void				ft_putstr_err(char *str);
void				init_var(t_var *var);
void				init_t(t_var *v, t_table *t);
void				iter_line(t_table *t, t_var *v);
void				display_sol(t_table *table, t_var *var);
void				with_args(char **argv, t_table *t, t_var *var);
void				hop(int k, int argc, int mode);
void				raise_fn(t_fknorm *fn, char **argv);
int					no_args(t_table *table, t_var *var);
int					mall_grid(char *map, t_table *table);
int					ft_putstr_zerr(char *str);
int					delta_count(t_table *t, t_var *v);
int					delta_diff_left(t_var *v);
int					delta_diff_right(t_table *t, t_var *v);

#endif
