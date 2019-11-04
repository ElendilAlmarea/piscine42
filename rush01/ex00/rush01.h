/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndrege <ndrege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:39:18 by ndrege            #+#    #+#             */
/*   Updated: 2019/07/14 20:00:02 by ndrege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>
# include <stdlib.h>

int		ft_fill(int **tab, int size);
void	ft_arg_topfloor(int **tab, int size, char *str, int *i);
void	ft_arg_sides(int **tab, int size, char *str, int *i);
void	ft_display(int **tab, int size);
int		ft_check_lign_l(int **tab, int x, int size);
int		ft_strlen(char *str);
int		ft_find_sol(int **tab, int x, int y, int size);
int		ft_count_arg(char *str);
int		ft_check_valid(int **tab, int x, int y, int nb);
int		ft_check_col_up(int **tab, int y, int size);
int		ft_check_lign_r(int **tab, int y, int size);
int		ft_check_col_d(int **tab, int y, int size);
int		ft_init_tab(int **tab, int size, char **argv, int *i);
int		ft_verif_arg(char *str, int size);
int		ft_checkall_col(int **tab, int size, int x);
int		ft_increm(int *x);
#endif
