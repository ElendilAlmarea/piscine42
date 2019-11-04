/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:54:18 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 20:08:50 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_H
# define F_H

# include <unistd.h>

int		ft_strlen(char *str);
int		the_end(void);
int		ft_atoi(char *str);
int		neg(int nb);
void	write_while(int *tab);
void	ft_putnbr(int nb);
void	add(int nb1, int nb2);
void	sub(int nb1, int nb2);
void	div(int nb1, int nb2);
void	mult(int nb1, int nb2);
void	mod(int nb1, int nb2);
void	op_select(int nb1, int nb2, char op, void (**oper)(int, int));

#endif
