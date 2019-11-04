/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:50:11 by yvanat            #+#    #+#             */
/*   Updated: 2019/07/18 20:08:54 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int		main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	void	(*oper[5])(int, int);

	if (argc != 4)
		return (0);
	if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '/'
			&& argv[2][0] != '*' && argv[2][0] != '%')
	{
		write(1, "0\n", 2);
		return (0);
	}
	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[3]);
	oper[0] = &add;
	oper[1] = &sub;
	oper[2] = &mult;
	oper[3] = &div;
	oper[4] = &mod;
	op_select(nb1, nb2, argv[2][0], oper);
	return (0);
}
