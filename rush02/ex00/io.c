/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enduperv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:48:05 by enduperv          #+#    #+#             */
/*   Updated: 2019/07/21 18:28:08 by enduperv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		ft_putstr_err(char *str)
{
	write(2, str, ft_strlen(str));
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
